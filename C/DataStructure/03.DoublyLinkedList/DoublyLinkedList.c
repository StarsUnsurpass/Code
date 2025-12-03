#define _CRT_SECURE_NO_WARNINGS

#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
* 创建一个新的节点并初始化数据
* @note 这是一个内部函数，通常不直接调用
* @param songData 包含歌曲信息的结构体
* @return 返回指向新创建节点的指针，如果内存分配失败则返回 NULL
*/
static Node* _createNode(Song songData) {
	// 为节点分配内存
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (!newNode) {
		perror("Failed to allocate memory for new node");
		return NULL;
	}

	// 初始化节点数据，为节点数据中的字符串成员分配内存并复制内容
	// songData中的字符串成员是指向字符串字面量的指针
	// 直接赋值会导致多个节点指向同一内存地址
	newNode->data.title = (char*)malloc(strlen(songData.title) + 1);
	newNode->data.artist = (char*)malloc(strlen(songData.artist) + 1);

	if (!newNode->data.title || !newNode->data.artist) {
		perror("Failed to allocate memory for song data");
		free(newNode->data.title);
		free(newNode->data.artist);
		free(newNode);
		return NULL;
	}

	strcpy(newNode->data.title, songData.title);
	strcpy(newNode->data.artist, songData.artist);
	newNode->data.duration = songData.duration;

	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

DoublyLinkedList* createList() {
	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if (!list) {
		perror("Failed to allocate memory for the list");
		return NULL;
	}

	// 初始化链表
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void freeList(DoublyLinkedList* list) {
	if (!list) {
		perror("List is NULL, nothing to free.\n");
		return;
	}

	Node* current = list->head;

	while (current != NULL) {
		Node* nextNode = current->next;
		free(current->data.title);
		free(current->data.artist);
		free(current);
		current = nextNode;
	}

	free(list);
}

bool append(DoublyLinkedList* list, Song songData) {
	if (!list) {
		perror("List is NULL, cannot append.");
		// 链表为空
		return false;
	}

	Node* newNode = _createNode(songData);
	if (!newNode) {
		// 节点创建失败
		return false;
	}

	if (list->head == NULL) {
		// 链表为空时，设置头节点和尾节点
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		// 链表非空时，将新节点添加到尾部
		list->tail->next = newNode; // 将当前节点的 next 指向新节点
		newNode->prev = list->tail; // 新节点的 prev 指向当前尾节点
		list->tail = newNode;		// 更新尾节点为新节点
	}

	list->size++;

	return true;
}

bool prepend(DoublyLinkedList* list, Song songData) {
	if (!list) {
		perror("List is NULL, cannot prepend.");
		return false; // 链表为空
	}

	Node* newNode = _createNode(songData);
	if (!newNode) {
		return false; // 节点创建失败
	}

	if (list->head == NULL) {
		// 链表为空，设置头节点和尾节点
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		// 链表非空时，将新节点添加到头部
		newNode->next = list->head; // 新节点的 next 指向当前头节点
		list->head->prev = newNode; // 当前头节点的 prev 指向新节点
		list->head = newNode;		// 更新头节点为新节点
	}

	list->size++;

	return true;
}

bool insertAfter(DoublyLinkedList* list, Node* targetNode, Song songData) {
	if (!list || !targetNode) {
		perror("List or target node is NULL, cannot insert.");
		return false; // 链表或目标节点为空
	}

	// 创建新的节点
	Node* newNode = _createNode(songData);

	if (!newNode) {
		return false; // 节点创建失败
	}

	newNode->next = targetNode->next; // 新节点的 next 指向目标节点的下一个节点
	newNode->prev = targetNode; // 新节点的 prev 指向目标节点
	if (targetNode->next != NULL) {
		targetNode->next->prev = newNode; // 确保不是在尾部插入
	}
	else {
		list->tail = newNode; // 如果目标节点是尾节点，更新尾节点为新节点
	}

	targetNode->next = newNode; // 目标节点的 next 指向新节点
	list->size++; // 增加链表的大小计数

	return true; // 成功插入节点
}

bool deleteNode(DoublyLinkedList* list, Node* nodeToDelete) {
	if (!list || !nodeToDelete) {
		perror("List or node to delete is NULL.");
		return false; // 链表或节点为空
	}

	if (nodeToDelete->prev != NULL) {
		nodeToDelete->prev->next = nodeToDelete->next; // 如果不是头节点，更新前一个节点的 next
	}
	else {
		list->head = nodeToDelete->next; // 如果是头节点，更新头节点
	}

	if (nodeToDelete->next != NULL) {
		nodeToDelete->next->prev = nodeToDelete->prev;
	}
	else {
		list->tail = nodeToDelete->prev;
	}

	free(nodeToDelete->data.title);
	free(nodeToDelete->data.artist);
	free(nodeToDelete);

	list->size--;

	return true;
}

Node* findByTitle(const DoublyLinkedList* list, const char* title) {
	if (!list || !title) {
		perror("List or title is NULL, cannot find.");
		return NULL;
	}

	Node* current = list->head;

	while (current != NULL) {
		if (strcmp(current->data.title, title) == 0) {
			return current;
		}

		current = current->next;
	}

	return NULL;
}

void printListForward(const DoublyLinkedList* list) {
	if (!list || !list->head) {
		printf("List is empty.\n");
		return;
	}

	printf("----Playlist (Size: %d, Forward)----\n", list->size);
	Node* current = list->head;
	int index = 1;
	while (current != NULL) {
		printf("%d. Title: %s, Artist: %s, Duration: %d second\n",
			index++, current->data.title, current->data.artist, current->data.duration);
		current = current->next;
	}
	printf("----End of Playlist----\n");
}

void printListBackward(const DoublyLinkedList* list) {
	if (!list || !list->head) {
		printf("List is empty.\n");
		return;
	}

	printf("----Playlist (Size: %d, Forward)----\n", list->size);
	Node* current = list->tail;
	int index = list->size;
	while (current != NULL) {
		printf("%d. Title: %s, Artist: %s, Duration: %d second\n",
			index--, current->data.title, current->data.artist, current->data.duration);
		current = current->prev;
	}
	printf("----End of Playlist----\n");
}