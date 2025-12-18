#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct LinkedQueue Queue;

Queue* queue_create(size_t element_size);

void queue_destroy(Queue** p_queue);

bool queue_enqueue(Queue* queue, const void* element_data);

bool queue_peek(const Queue* queue, void* output_buffer);

bool queue_is_empty(const Queue* queue);

size_t queue_get_size(const Queue* queue);