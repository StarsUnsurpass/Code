#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态数组 Dynamic Array
typedef struct {
	int* data; // data指向一个动态分配的内存，数组的首地址
	// data -> int arr[capacity] => data -> &arr[0]
	// char* name
	size_t size;		// 当前元素的个数
	size_t capacity;	// 总个数
} Array;

// create
Array* create_array(size_t init_capacity) {
	Array* arr = (Array*)malloc(sizeof(Array));
	if (!arr) {
		return NULL;
	}

	arr->data = (int*)malloc(init_capacity * sizeof(int));
	if (!arr->data) {
		free(arr);
		return NULL;
	}

	arr->size = 0;
	arr->capacity = init_capacity;

	return arr;
}

int append(Array* arr, int value) {
	if (!arr) {
		return 0;
	}

	if (arr->size >= arr->capacity) {
		size_t new_capacity = arr->capacity * 2;
		int* temp = (int*)realloc(arr->data, new_capacity * sizeof(int));
		if (!temp) {
			return 0;
		}

		arr->data = temp;
		arr->capacity = new_capacity;
	}

	arr->data[arr->size++] = value;
	
	return 1;
}

void print_array(const Array* arr) {
	if (!arr) {
		return;
	}

	printf("\n数组元素：\n");
	for (size_t i = 0; i < arr->size; i++) {
		printf("%d ", arr->data[i]);
	}
	printf("\n元素个数：%zu\n容量：%zu\n", arr->size, arr->capacity);
}

void free_array(Array* arr) {
	if (!arr) {
		return;
	}
	free(arr->data);
	free(arr);
}

int main03(void) {
	Array* arr = create_array(4);

	if (!arr) {
		printf("创建数组失败！\n");
		return 1;
	}

	append(arr, 1);
	append(arr, 2);
	append(arr, 3);
	append(arr, 4);
	print_array(arr);

	append(arr, 5);
	append(arr, 6);
	append(arr, 7);
	print_array(arr);

	append(arr, 5);
	append(arr, 6);
	append(arr, 7);
	append(arr, 5);
	append(arr, 6);
	append(arr, 7); 
	append(arr, 5);
	append(arr, 6);
	append(arr, 7);
	print_array(arr);

	free_array(arr);

	return EXIT_SUCCESS;
}