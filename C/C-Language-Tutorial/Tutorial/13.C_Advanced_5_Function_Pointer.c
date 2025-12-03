#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//函数指针（Function pointer）
//指针，变量，数组，字符串，结构体，指针

//指针指向函数

//回调函数

int (*myFunctionPointer)(int, int);
//myFunctionPointer -> int f(int num1, int num2);

//int add(int a, int b);

int main11(void) {
	// 指向函数
	myFunctionPointer = add;

	int result = myFunctionPointer(2, 3);

	// 通过指针调用函数
	printf("The result is %d\n", result);

	// 函数指针的用途：实现回调函数
	// 回调函数允许将一个函数作为参数传递给另一个函数，这样，当特定的事件发生时，可以调用传递的参数
	// 事件驱动编程

	return EXIT_SUCCESS;
}

int add(int a, int b) {
	return a + b;
}