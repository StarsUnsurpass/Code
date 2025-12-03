// 再谈typedef
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Point;
 
int main14(void) {
	// 为基本数据结构起别名
	// 企业开发中写入头文件
	typedef unsigned long ulong;
	typedef uint32_t u32;

	ulong number = 10000;

	return EXIT_SUCCESS;
}