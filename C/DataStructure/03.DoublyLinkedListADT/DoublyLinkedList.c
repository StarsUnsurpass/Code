#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <errno.h>

struct DListNode {
	void* data;
	struct DListNode* next;
	struct DListNode* prev;
};

// 内存池，高效地管理链表节点的内存分配和释放
typedef struct MemoryPool {
	DListNode* pool_memory;
	DListNode* free_list_head;
} MemoryPool;

struct DoublyLinkedList {
	DListNode* head;
	DListNode* tail;
	size_t size;
	// 互斥锁，确保多线程环境下的线程安全
	mtx_t lock;
	MemoryPool* pool;
	FreeFunc user_free_func;
};

static MemoryPool* MemoryPool_Create(size_t initial_capacity) {
	if (initial_capacity == 0) {
		perror("Invalid initial capacity for memory pool");
		return NULL;
	}
	MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
	if(!pool) {
		perror("Failed to allocate memory for MemoryPool");
		return NULL;
	}
	pool->pool_memory = (DListNode*)malloc(sizeof(DListNode) * initial_capacity);
	if(!pool->pool_memory) {
		free(pool);
		perror("Failed to allocate memory for pool nodes");
		return NULL;
	}

	// 初始化空闲列表，将所有节点链接起来
	pool->free_list_head = &pool->pool_memory[0];
	for (size_t i = 0; i < initial_capacity - 1; ++i) {
		pool->pool_memory[i].next = &pool->pool_memory[i + 1];
	}
	// 最后一个节点的下一个指针设为NULL
	pool->pool_memory[initial_capacity - 1].next = NULL;
	return pool;
}

static void MemoryPoolDestroy(MemoryPool* pool) {
	if (pool) {
		free(pool->pool_memory);
		free(pool);
	}
}

static DListNode* MemoryPoolAllocate(MemoryPool* pool) {
	if (!pool || !pool->free_list_head) {
		return NULL; // 内存池为空或无可用节点
	}
	// 从空闲列表中取出一个节点
	DListNode* node = pool->free_list_head;
	pool->free_list_head = node->next;

	return node;
}

static void MemoryPoolFree(MemoryPool* pool, DListNode* node) {
	if (!pool || !node) {
		return;
	}
	// 将节点放回空闲列表
	node->next = pool->free_list_head;
	pool->free_list_head = node;
}

// 实例的工厂函数（设计模式）
DoublyLinkedList* List_Create(size_t initial_capacity, FreeFunc free_func) {
	if (initial_capacity == 0) {
		errno = EINVAL;
		perror("Initial capacity must be greater than zero");
		return NULL;
	}

	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if (!list) {
		perror("Failed to allocate memory for DoublyLinkedList");
		return NULL;
	}

	list->pool = MemoryPool_Create(initial_capacity);
	if (!list->pool) {
		free(list);
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->user_free_func = free_func;

	// 初始化互斥锁，确保线程安全
	if (mtx_init(&list->lock, mtx_plain) != thrd_success) {
		free(list);
		perror("Failed to initialize mutex");
		return NULL;
	}
	
	return list;
}

void List_Destroy(DoublyLinkedList** list_ptr) {
	if (!list_ptr || !*list_ptr) {
		return;
	}

	DoublyLinkedList* list = *list_ptr;

	mtx_lock(&list->lock);

	DListNode* current = list->head;
	while (current) {
		DListNode* next_node = current->next;
		if (list->user_free_func) {
			list->user_free_func(current->data);
		}

		current = next_node;
	}
	
	MemoryPoolDestroy(list->pool);
	mtx_unlock(&list->lock);
	mtx_destroy(&list->lock);
	free(list);
	*list_ptr = NULL;
}

// 内部辅助函数，创建一个新的节点并初始化其数据
static DListNode* _internal_CreateNode(DoublyLinkedList* list, const void* data) {
	if(!list || !list->pool) {
		return NULL;
	}

	DListNode* new_node = MemoryPoolAllocate(list->pool);
	if (!new_node) {
		perror("Memory pool exhausted, failed to allocate new node");
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

bool List_Append(DoublyLinkedList* list, void* data) {
	if(!list || !data) {
		errno = EINVAL;
		perror("List or data is NULL");
		return false;
	}

	mtx_lock(&list->lock);

	DListNode* new_node = _internal_CreateNode(list, data);
	
	if (!new_node) {
		mtx_unlock(&list->lock);
		return false;
	}

	if(list->tail == NULL) {
		list->head = new_node;
		list->tail = new_node;
	}
	else {
		list->tail->next = new_node;
		new_node->prev = list->tail;
		list->tail = new_node;
	}

	list->size++;
	mtx_unlock(&list->lock);

	return true;
}

bool List_Prepend(DoublyLinkedList* list, const void* data) {
	if (!list || !data) {
		errno = EINVAL;
		perror("List or data is NULL");
		return false;
	}
	mtx_lock(&list->lock);
	DListNode* new_node = _internal_CreateNode(list, data);

	if (!new_node) {
		mtx_unlock(&list->lock);
		return false;
	}
	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
	}
	else {
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
	}
	list->size++;
	mtx_unlock(&list->lock);
	return true;
}

void List_DeleteNode(DoublyLinkedList* list, DListNode* node) {
	if(!list || !node) {
		errno = EINVAL;
		perror("List or node is NULL");
		return;
	}
	mtx_lock(&list->lock);

	// 更新前驱节点的next指针
	if (node->prev) {
		node->prev->next = node->next;
	} else {
		// 删除的是头节点
		list->head = node->next;
	}
	// 更新后继节点的prev指针
	if (node->next) {
		node->next->prev = node->prev;
	} else {
		// 删除的是尾节点
		list->tail = node->prev;
	}
	if (list->user_free_func) {
		list->user_free_func(node->data);
	}

	MemoryPoolFree(list->pool, node);
	list->size--;
	mtx_unlock(&list->lock);
}

DListNode* List_Find(DoublyLinkedList* list, const void* data_to_find, CompareFunc compare_func) {
	if(!list || !data_to_find || !compare_func) {
		errno = EINVAL;
		perror("Invalid argument(s) to List_Find");
		return NULL;
	}
	mtx_lock(&list->lock);
	DListNode* current = list->head;
	while (current) {
		if (compare_func(current->data, data_to_find) == 0) {
			mtx_unlock(&list->lock);
			return current; // 找到匹配节点
		}
		current = current->next;
	}
	mtx_unlock(&list->lock);
	return NULL; // 未找到匹配节点
}

void List_ForEach(DoublyLinkedList* list, ActionFunc action_func, void* context){
	if (!list || !action_func) {
		errno = EINVAL;
		perror("Invalid argument(s) to List_ForEach");
		return;
	}

	mtx_lock(&list->lock);

	DListNode* current = list->head;

	while(current) {
		action_func(current->data, context);
		current = current->next;
	}

	mtx_unlock(&list->lock);
}

size_t List_GetSize(const DListNode* node) {
	return node ? node->data : NULL;
}

bool List_InsertAfter(DoublyLinkedList* list, DListNode* node, const void* data) {
	if (!list || !node || !data) {
		errno = EINVAL;
		perror("Invalid argument(s) to List_InsertAfter");
		return false;
	}
	mtx_lock(&list->lock);
	DListNode* new_node = _internal_CreateNode(list, data);
	if (!new_node) {
		mtx_unlock(&list->lock);
		return false;
	}
	new_node->next = node->next;
	new_node->prev = node;
	if (node->next) {
		node->next->prev = new_node;
	} else {
		// 插入在尾节点之后，更新尾指针
		list->tail = new_node;
	}
	node->next = new_node;
	list->size++;
	mtx_unlock(&list->lock);
	return true;
}