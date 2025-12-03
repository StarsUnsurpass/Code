#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <time.h>

void addString(char*** array, int* size, const char* str);

void printStrings(char** array, int size);

int main9(void) {
	//三级指针案例：字符串无限追加的应用

	char** strArray = NULL; // 初始化字符数组

	int size = 0;

	addString(&strArray, &size, "Hello");
	addString(&strArray, &size, ", ");
	addString(&strArray, &size, "World");
	addString(&strArray, &size, "!");

	printStrings(strArray, size);

	for (size_t i = 0; i < size; i++) {
		free(strArray[i]);
	}

	free(strArray);


	return EXIT_SUCCESS;
}

void addString(char*** array, int* size, const char* str) {
	char** temp = (char**)realloc(*array, (*size + 1) * sizeof(char*));

	if (temp == NULL) {
		printf("Failed to allocate memory\n");
		return;
	}

	*array = temp;

	// 分配内存并且复制字符串
	(*array)[*size] = (char*)malloc(strlen(str) + 1);
	if ((*array)[*size] != NULL) {
		strcpy_s((*array)[*size], strlen(str) + 1, str);
		(*size)++;
	}
	else {
		fprintf(stderr, "Error!\n");
	}
}

void printStrings(char** array, int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%s", array[i]);
	}
}