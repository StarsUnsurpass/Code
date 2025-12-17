#include "LinkedStack.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	void* data;
	struct Node* next;
} Node;

struct LinkedStack {
	Node* top;
	size_t element_size;
	size_t size;
};

Stack* stack_create(size_t element_size) {
	if (element_size == 0) {
		return NULL;
	}

	Stack* stack = (Stack*)malloc(sizeof(Stack));

	if (stack == NULL) {
		return NULL;
	}

	stack->top = NULL;

	stack->element_size = element_size;

	stack->size = 0;

	return stack;
}

void stack_destroy(Stack** p_stack) {
	if (p_stack == NULL || *p_stack == NULL) {
		return;
	}

	Stack* stack = *p_stack;

	Node* current = stack->top;

	while (current != NULL) {
		Node* temp = current;

		current = current->next;

		free(temp->data);

		free(temp);
	}

	free(stack);

	*p_stack = NULL;
}

bool stack_push(Stack* stack, const void* element_data) {
	if (stack == NULL || element_data == NULL) {
		return false;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		return false;
	}

	new_node->data = malloc(stack->element_size);

	if (new_node->data == NULL) {
		free(new_node);

		return false;
	}

	memcpy(new_node->data, element_data, stack->element_size);

	new_node->next = stack->top;

	stack->top = new_node;

	stack->size++;

	return true;
}

bool stack_pop(Stack* stack, void* output_buffer) {
	if (stack_is_empty(stack) || output_buffer == NULL) {
		return false;
	}

	Node* node_to_pop = stack->top;

	memcpy(output_buffer, node_to_pop->data, stack->element_size);

	stack->top = node_to_pop->next;

	free(node_to_pop->data);

	free(node_to_pop);


	stack->size--;

	return true;
}

bool stack_peek(const Stack* stack, void* output_buffer) {
	if (stack_is_empty(stack) || output_buffer == NULL) {
		return false;
	}

	memcpy(output_buffer, stack->top->data, stack->element_size);

	return true;
}

bool stack_is_empty(const Stack* stack) {
	if (stack == NULL) {
		return true;
	}

	return stack->top == NULL;
	// return stack->size == 0;
}

size_t stack_get_size(const Stack* stack) {
	if (stack == NULL) {
		return 0;
	}

	return stack->size;
}