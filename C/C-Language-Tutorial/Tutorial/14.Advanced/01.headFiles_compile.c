// 再谈头文件与编译
#include <stdio.h>
#include <stdlib.h>
#include "math_operations.h"

int main01(void) {
	// 头文件
	// 1.组织性
	// 2.重用性
	// 3.编译效率
	// 4.避免重复包含
	// 头文件用来声明
	// 源文件用来实现

	int result = add(199, 8928);
	printf("%d\n", result);


	return EXIT_SUCCESS;
}