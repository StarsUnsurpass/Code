// malloc函数动态内存分配的使用与释放
#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main03(void) {
	// 静态数组的声明和初始化
	int static_arr[5] = { 1, 2, 3, 4, 5 };
	printf("静态数组的内容：\n");
	for (size_t i = 0; i < 5; i++) {
		printf("%d ", static_arr[i]);
	}
	printf("\n");




	// 动态内存分配
	// malloc返回void*值
	// C语言中void*用于泛型编程
	int* dynamic_arr = malloc(5 * sizeof(int));

	if (dynamic_arr == NULL) {
		perror("动态数组分配失败");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 5; i++) {
		dynamic_arr[i] = (i + 1) * 10;
	}
	puts("动态数组的内容：");
	for (size_t i = 0; i < 5; i++) {
		printf("%d ", dynamic_arr[i]);
	}

	free(dynamic_arr);

	

	return 0;
}