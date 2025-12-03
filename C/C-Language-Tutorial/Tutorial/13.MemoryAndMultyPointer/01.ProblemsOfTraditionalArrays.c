#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

int main01(void) {
	// 传统数组的问题

	// 动态内存分配
	// 1.处理可变大小的数据	灵活性
	// 2.高效的数据结构		效率
	// 3.资源优化			能够控制

	// 以往传统形式
	char buffer[1000] = {0};
	// 1.灵活性降低，整个程序走下来，都依赖预设编译前的大小
	// 2.内存的浪费与安全隐患（内存泄漏）
	// 3.应用受限

	return 0;
}