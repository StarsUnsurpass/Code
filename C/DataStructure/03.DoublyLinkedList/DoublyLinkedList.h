#pragma once
#include <stdbool.h>

// 模拟节点存储数据
typedef struct {
	char* title;
	char* artist;
	int duration;
} Song;

// 双向链表
typedef struct Node {
	Song data;
	struct Node* next;
	struct Node* prev;
} Node;

// 定义一个管理器
typedef struct {
	Node* head;
	Node* tail;
	int size;
} DoublyLinkedList;

DoublyLinkedList* createList();

void freeList(DoublyLinkedList* list);

bool append(DoublyLinkedList* list, Song songData);

bool prepend(DoublyLinkedList* list, Song songData);

bool insertAfter(DoublyLinkedList* list, Node* targetNode, Song songData);

bool deleteNode(DoublyLinkedList* list, Node* nodeToDelete);

Node* findByTitle(const DoublyLinkedList* list, const char* title);

void printListForward(const DoublyLinkedList* list);

void printListBackward(const DoublyLinkedList* list);