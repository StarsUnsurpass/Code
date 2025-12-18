#include "SharedStack.h"
#include <stdlib.h>
#include <string.h>

struct SharedStack {
	void* data;
	size_t capacity;
	size_t element_size;
	int top1;
	int top2;
};

Stack* stack_create(size_t total_capacity, size_t element_size) {
	if (total_capacity == 0 || element_size == 0) {
		return NULL;
	}

	Stack* s = (Stack*)malloc(sizeof(Stack));

	if (!s) {
		return NULL;
	}

	s->data = malloc(total_capacity * element_size);

	if (!s->data) {
		free(s);

		return NULL;
	}

	s->capacity = total_capacity;
	s->element_size = element_size;
	s->top1 = -1;
	s->top2 = (int)total_capacity;

	return s;
}

void stack_destroy(Stack** p_stack) {
	if (p_stack && *p_stack) {
		free((*p_stack)->data);
		free(*p_stack);
		*p_stack = NULL;
	}
}

bool stack_is_full(const Stack* stack) {
	if (!stack) {
		return false;
	}

	return stack->top1 + 1 == stack->top2;
}

bool stack_is_empty(const Stack* stack, StackNumber num) {
	if (!stack) {
		return true;
	}

	if (num == STACK_ONE) {
		return stack->top1 == -1;
	}
	else {
		return stack->top2 == (int)stack->capacity;
	}
}

bool stack_push(Stack* stack, StackNumber num, const void* element_data) {
	if (!stack || !element_data || stack_is_full(stack)) {
		return false;
	}

	void* target_address;

	if (num == STACK_ONE) {
		stack->top1++;
		target_address = (char*)stack->data + (stack->top1 * stack->element_size);
	}
	else {
		stack->top2--;
		target_address = (char*)stack->data + (stack->top2 * stack->element_size);
	}

	memcpy(target_address, element_data, stack->element_size);

	return true;
}

bool stack_pop(Stack* stack, StackNumber num, void* output_buffer) {
	if (!stack || !output_buffer || stack_is_empty(stack, num)) {
		return false;
	}

	void* source_address;

	if (num == STACK_ONE) {
		source_address = (char*)stack->data + (stack->top1 * stack->element_size);

		memcpy(output_buffer, source_address, stack->element_size);

		stack->top1--;
	}
	else {
		source_address = (char*)stack->data + (stack->top2 * stack->element_size);

		memcpy(output_buffer, source_address, stack->element_size);

		stack->top2++;
	}
}

bool stack_peek(const Stack* stack, StackNumber num, void* output_buffer) {
	if (!stack || !output_buffer || stack_is_empty(stack, num)) {
		return false;
	}

	void* source_address;

	if (num == STACK_ONE) {
		source_address = (char*)stack->data + (stack->top1 * stack->element_size);
	}
	else {
		source_address = (char*)stack->data + (stack->top2 * stack->element_size);
	}

	memcpy(output_buffer, source_address, stack->element_size);

	return true;
}

size_t stack_get_size(const Stack* stack, StackNumber num) {
	if (!stack) {
		return 0;
	}

	if (num == STACK_ONE) {
		return (size_t)(stack->top1 + 1);
	}
	else {
		return (size_t)(stack->capacity - stack->top2);
	}
}

size_t stack_get_total_capacity(const Stack* stack) {
	if (!stack) {
		return 0;
	}

	return stack->capacity;
}