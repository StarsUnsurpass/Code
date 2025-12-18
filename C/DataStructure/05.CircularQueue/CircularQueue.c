#include "CircularQueue.h"
#include <stdlib.h>
#include <string.h>

struct CircularQueue {
	void* data;
	size_t capacity;
	size_t element_size;
	size_t size;
	int front;
	int rear;
};

Queue* queue_create(size_t capacity, size_t element_size) {
	if (capacity == 0 || element_size == 0) {
		return NULL;
	}

	Queue* q = (Queue*)malloc(sizeof(Queue));

	if (!q) {
		return NULL;
	}

	q->data = malloc(capacity * element_size);

	if (!q->data) {
		free(q);
		return NULL;
	}

	q->capacity = capacity;
	q->element_size = element_size;
	q->size = 0;
	q->front = 0;
	q->rear = 0;

	return q;
}

void queue_destroy(Queue** p_queue) {
	if (p_queue && *p_queue) {
		free((*p_queue)->data);
		free(*p_queue);
		*p_queue = NULL;
	}
}

bool queue_enqueue(Queue* queue, const void* element_data) {
	if (!queue || !element_data) {
		return NULL;
	}

	if (queue->size == queue->capacity) {
		return false;
	}

	void* target_address = (char*)queue->data + (queue->rear * queue->element_size);

	memcpy(target_address, element_data, queue->element_size);

	queue->rear = (queue->rear + 1) % queue->capacity;

	queue->size++;
}

bool queue_dequeue(Queue* queue, void* output_buffer) {
	if (!queue || !output_buffer) {
		return false;
	}

	if (queue->size == 0) {
		return false;
	}

	void* source_address = (char*)queue->data + (queue->front * queue->element_size);

	memcpy(output_buffer, source_address, queue->element_size);

	queue->front = (queue->front + 1) % queue->capacity;

	queue->size--;

	return true;
}

bool queue_peek(const Queue* queue, void* output_buffer) {
	if (!queue || !output_buffer) {
		return false;
	}

	if (queue->size == 0) {
		return false;
	}

	void* source_address = (char*)queue->data + (queue->front * queue->element_size);

	memcpy(output_buffer, source_address, queue->element_size);

	return true;
}

bool queue_is_empty(const Queue* queue) {
	if (!queue) return true;

	return queue->size == 0;
}

bool queue_is_full(const Queue* queue) {
	if (!queue) return true;

	return queue->size == queue->capacity;
}

size_t queue_get_size(const Queue* queue) {
	if (!queue) return 0;

	return queue->size;
}

size_t queue_get_capacity(const Queue* queue) {
	if (!queue) return 0;

	return queue->capacity;
}