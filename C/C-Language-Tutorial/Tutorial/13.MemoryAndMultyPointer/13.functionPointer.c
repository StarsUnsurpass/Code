// FunctionPointer函数指针的概念
#include <stdio.h>
#include <stdlib.h>

// 声明一个指针指向函数
// 返回类型 (*指针变量名) (参数类型);
int (*myFunctionPointer)(int, int);

int add1(int a, int b);

int main13(void) {
	// 指向函数
	myFunctionPointer = add1;

	// 指针可操作：变量，数组，字符串，结构体，指针
	// 通过指针调用函数
	int result = myFunctionPointer(2, 3);

	printf("The result is %d\n", result);

	// 函数指针的用途：实现回调函数
	// 回调函数允许将一个函数作为参数传递给另一个函数，这样，当特定的事件发生时，可以调用传递的参数
	// 事件驱动编程
	// 不同的执行条件不同的操作场景

	return EXIT_SUCCESS;
}

int add1(int a, int b) {
	return a + b;
}