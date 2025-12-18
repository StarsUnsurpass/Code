#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char* key;
	char* value;
	struct Node* next;
} Node;

struct HashTable {
	Node** buckets;
	size_t capacity;
	size_t size;
};

static size_t hash_function(const char* key, size_t capacity) {
	unsigned long hash_value = 0;

	for (size_t i = 0; key[i] != '\0'; i++) {
		hash_value += key[i];
	}

	return hash_value % capacity;
}

HashTable* ht_create(size_t capacity) {
	if (capacity == 0) return NULL;

	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));

	if (!ht) return NULL;

	ht->buckets = (Node**)calloc(capacity, sizeof(Node*));

	if (!ht->buckets) {
		free(ht);

		return NULL;
	}

	ht->capacity = capacity;

	ht->size = 0;

	return ht;
}

void ht_destroy(HashTable** p_ht) {
	if (!p_ht || !*p_ht) return;

	HashTable* ht = *p_ht;

	for (size_t i = 0; i < ht->capacity; i++) {
		Node* current = ht->buckets[i];

		while (current != NULL) {
			Node* to_free = current;
			
			current = current->next;

			if (to_free->key) {
				free(to_free->value);
			}

			free(to_free);
		}
	}

	free(ht->buckets);

	free(ht);

	*p_ht = NULL;
}

bool ht_set(HashTable* ht, const char* key, const char* value) {
	if (!ht || !key || !value) return false;

	size_t index = hash_function(key, ht->capacity);

	Node* current = ht->buckets[index];

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			free(current->value);

			current->value = (char*)malloc(strlen(value) + 1);

			if (!current->value) return false;

			strcpy(current->value, value);

			return true;
		}

		current = current->next;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (!new_node) return false;

	new_node->key = (char*)malloc(strlen(key) + 1);

	new_node->value = (char*)malloc(strlen(value) + 1);

	if (!new_node->key || !new_node->value) {
		free(new_node->key);

		free(new_node->value);

		free(new_node);

		return false;
	}

	strcpy(new_node->key, key);

	strcpy(new_node->value, value);

	new_node->next = ht->buckets[index];

	ht->buckets[index] = new_node;

	ht->size++;

	return true;
}

const char* ht_get(const HashTable* ht, const char* key) {
	if (!ht || !key) return NULL;

	size_t index = hash_function(key, ht->capacity);

	Node* current = ht->buckets[index];

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}

		current = current->next;
	}

	return NULL;
}

bool ht_remove(HashTable* ht, const char* key) {
	if (!ht || !key) return false;

	size_t index = hash_function(key, ht->capacity);

	Node* current = ht->buckets[index];

	Node * prev = NULL;

	while (current != NULL && strcmp(current->key, key) != 0) {
		prev = current;

		current = current->next;
	}

	if (prev == NULL) {
		ht->buckets[index] = current->next;
	}
	else {
		prev->next = current->next;
	}

	free(current->key);
	free(current->value);
	free(current);

	ht->size--;

	return true;
}

void ht_print(const HashTable* ht) {
	if (!ht) {
		printf("HashTable is NULL.\n");

		return;
	}

	printf("--- HashTable (capacity: %zu, size: %zu) ---\n", ht->capacity, ht->size);

	for (size_t i = 0; i < ht->capacity; i++) {
		printf("Bucket[%zu]: ", i);

		Node* current = ht->buckets[i];

		if (current == NULL) {
			printf("-> NULL\n");
		}
		else {
			while (current != NULL) {
				printf("-> [K:\"%s\", V:\"%s\"] ", current->key, current->value);

				current = current->next;
			}

			printf("-> NULL\n");
		}
	}

	printf("------------------------------------------\n\n");
}