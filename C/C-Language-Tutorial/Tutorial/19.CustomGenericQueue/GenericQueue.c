#include "GenericQueue.h"
#include <stdlib.h>
#include <string.h>

// 创建一个新的泛型队列
GenericQueue* Queue_Create(void) {
	GenericQueue* queue = (GenericQueue*)malloc(sizeof(GenericQueue));

	if (queue == NULL) {
		return NULL;
	}

	queue->head = queue->tail = NULL;

	queue->size = 0;

	return queue;
}