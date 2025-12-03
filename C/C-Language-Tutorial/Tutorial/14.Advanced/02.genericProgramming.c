// 泛型编程：比较与排序
// 高可用
#include <stdio.h>
#include <stdlib.h>

int compare_value1(const void* a, const void* b);

void generic_sort1(void* array, size_t element_size, size_t element_count, int (*compare)(const void*, const*));

int main02(void) {
	int args[] = { -2, 95, 5892, 1, 10, 33 };
	size_t args_count = sizeof(args) / sizeof(args[0]);

	int num1 = 1;
	int num2 = 2;

	printf("%d\n", compare_value1(&num1, &num2));

	generic_sort1(args, sizeof(args[0]), args_count, compare_value1);

	for (size_t i = 0; i < args_count; i++) {
		printf("%d ", args[i]);
	}
	printf("\n");


	return EXIT_SUCCESS;
}

int compare_value1(const void* a, const void* b) {
	int args1 = *(const int*)a;
	int args2 = *(const int*)b;

	if (args1 < args2) return -1;
	if (args1 > args2) return 1;

	return 0;
}

void generic_sort1(void* array, size_t element_size, size_t element_count, int (*compare)(const void*, const*)) {
	qsort(array, element_count, element_size, compare);
}