// C语言函数参数中的数组传递
#include <stdio.h>
#include <stdlib.h>

// void func(int a, int b);
// void printfArray(int arr[], int size);
void printArray(const int* arr, int size);

int main01(void) {
	int numbers1[] = { 1, 2, 3, 4, 5, 6, 7 };
	int numbers2[] = { 1, 7, 3, 2, 5, 6, 8 };
	int numbers3[] = { 1, 5, 3, 0, 5, 3, 9 };

	printArray(numbers1, sizeof(numbers1) / sizeof(numbers1[0]));
	printArray(numbers2, sizeof(numbers2) / sizeof(numbers2[0]));
	printArray(numbers3, sizeof(numbers3) / sizeof(numbers3[0]));

	return EXIT_SUCCESS;
}

void printArray(const int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}