#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct Stack Stack;

// 创建一个新的栈，指定容量和元素大小。
Stack* stack_create(size_t capacity, size_t element_size);

// 销毁栈，释放所有相关资源。
void stack_destroy(Stack** stack);

// 将一个元素压入栈顶。
bool stack_push(Stack* stack, const void* element_data);

// 从栈顶弹出一个元素。
bool stack_pop(Stack* stack, void* output_buffer);

// 查看栈顶元素但不弹出。
bool stack_peek(Stack* stack, void* output_buffer);

bool stack_is_empty(const Stack* stack);

bool stack_is_full(const Stack* stack);

size_t stack_get_size(const Stack* stack);

size_t stack_get_capacity(const Stack* stack);