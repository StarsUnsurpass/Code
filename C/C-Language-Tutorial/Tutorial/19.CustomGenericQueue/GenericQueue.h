#pragma once

#include "TypeDefinitions.h"

// 泛型队列结构体
typedef struct GenericQueueNode {
	GenericValue value;	// 存储实际的数据
	DataType type;		// 数据类型
	struct GenericQueueNode* next; // 指向下一个节点的指针
} GenericQueueNode;

typedef struct {
	GenericQueueNode* head;
	GenericQueueNode* tail;
	size_t size;
} GenericQueue;

GenericQueue* Queue_Create(void);
void Queue_Destroy(GenericQueue* queue);
bool Queue_Enqueue(GenericQueue* queue, GenericValue value, DataType type);
bool Queue_Dequeue(GenericQueue* queue, GenericValue value, DataType type);
size_t Queue_Size(const GenericQueue* queue);
bool Queue_IsEmpty(const GenericQueue* queue);