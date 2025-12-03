#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int x;
	int y;
} Pointer;

int main12(void) {
	//typedef
	//给基本数据类型创建别名
	//企业开发中写到头文件中
	typedef unsigned long ulong;
	typedef uint32_t u32;

	ulong nuber = 12345678;
	u32 num = 1;
	//Pointer p;


	return EXIT_SUCCESS;
}