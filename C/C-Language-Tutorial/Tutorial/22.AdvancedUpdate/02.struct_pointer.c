// 结构体指针成员：再谈动态内存、堆内存、栈内存
// 栈
// 堆
// 代码区：存放机器指令
// 静态区（全局区）：存放全局变量
#include <stdio.h>
#include <stdlib.h>

int main02(void) {
	int n;
	printf("input number:\n");
	scanf_s("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		fprintf(stderr, "内存分配失败！\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	printf("数组内容：\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%p\n", &arr[i]);
	}

	free(arr);
	arr = NULL;

	return EXIT_SUCCESS;
}