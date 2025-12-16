#include "SequentialStack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 栈的实际内部结构，对用户不可见
struct Stack {
	// 指向存储数据的连续内存块（我们的“数组”）
	void* data;
	// 栈的容量（可以存储多少个元素）
	size_t capacity;
	// 每个元素的大小（以字节为单位）
	size_t element_size;
	// 当前栈顶索引（-1表示空栈）
	int top;
};

Stack* stack_create(size_t capacity, size_t element_size) {
	if (capacity == 0 || element_size == 0) {
		return NULL; // 无效参数
	}

	// 为栈结构体本身分配内存
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		return NULL; // 内存分配失败
	}

	// 为存储数据的数组分配内存
	stack->data = malloc(capacity * element_size);
	if (stack->data == NULL) {
		free(stack);
		return NULL;
	}

	stack->capacity = capacity;
	stack->element_size = element_size;
	stack->top = -1; // -1代表空栈

	return stack;
}

void stack_destroy(Stack** p_stack) {
	if (p_stack == NULL || *p_stack == NULL) {
		return;
	}

	free((*p_stack)->data); // 释放数据区内存
	free(*p_stack);			// 适当栈结构体内存
	*p_stack = NULL;		// 将外部指针置为NULL，防止野指针
}

bool stack_push(Stack* stack, const void* element_data) {
	if (stack == NULL || element_data == NULL) {
		return false;
	}

	if (stack_is_full(stack)) {
		return false;
	}

	stack->top++;

	// 计算出新元素在物理内存中应该存放的位置
	// 使用（char*）是因为对 void* 的指针算数不是标准C
	// char* 按字节移动，最为安全
	void* target_address = (char*)stack->data + (stack->top * stack->element_size);
	// C语言中，指针算数是基于类型的，所以需要将 void* 转换为 char*
	// 因为 char 是 1 字节大小，所以可以按字节计算偏移
	// C语言里不允许对 void* 进行指针算数运算，void* + 1 是不合法的
	// 因此，当我们把任何指针类型转换为 char* 后，相当于告诉编译器：
	// 把整个指针看作一个字节数组来处理，这样就可以按字节进行偏移了（指向一个单字节数据块的指针）

	memcpy(target_address, element_data, stack->element_size);

	return true;
}

bool stack_pop(Stack* stack, void* output_buffer) {
	if (stack == NULL || output_buffer == NULL) {
		return false;
	}

	if (stack_is_empty(stack)) {
		return false;
	}

	void* source_address = (char*)stack->data + (stack->top * stack->element_size);

	memcpy(output_buffer, source_address, stack->element_size);
	// int received_value;
	// bool success = stack_pop(my_stack, &received_size);
	// 将栈顶数据拷贝到用户缓冲区

	stack->top--;
	// 逻辑删除，通过移动指针来宣告一块数据无效，而不是花时间去清理它

	return true;
}

bool stack_peek(Stack* stack, void* output_buffer) {
	if (stack == NULL || output_buffer == NULL) {
		return false;
	}

	if (stack_is_empty(stack)) {
		return false;
	}

	void* source_address = (char*)stack->data + (stack->top * stack->element_size);
	memcpy(output_buffer, source_address, stack->element_size);

	return true;
}

bool stack_is_empty(const Stack* stack) {
	if (stack == NULL) {
		return true;
	}

	return stack->top == -1;
}

bool stack_is_full(const Stack* stack) {
	if (stack == NULL) {
		return false;
	}

	return (size_t)(stack->top + 1) >= stack->capacity;
}

size_t stack_get_capacity(const Stack* stack) {
	if (stack == NULL) {
		return 0;
	}

	return stack->capacity;
}

size_t stack_get_size(const Stack* stack) {
	if (stack == NULL) {
		return 0;
	}

	return (size_t)(stack->top + 1);
}