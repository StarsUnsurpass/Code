// 函数指针与callback回调函数的作用
// 回调函数：传递给另一个函数的函数，允许在后者中调用前者
// 这种机制可以在不同的时间点或条件下根据需要执行特定的功能
// 为什么使用回调函数：代码更加灵活和可重用性（分模块）
// 可以根据不同的情况动态地改变执行操作
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// void (*Callback)(int)
// 复用性低

typedef void (*Callback)(int);

// 传递一个指向函数的指针
void traverseArray(int* array, int size, Callback callback);
void printElement(int element);
void doubleElement(int element);
void checkIfEven(int element);

//int fun(int a) {
//	return a;
//}

int main16(void) {
	/*Callback fun1 = fun;
	Callback fun2 = fun;*/

	int numbers[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	traverseArray(numbers, size, printElement);
	traverseArray(numbers, size, doubleElement);
	traverseArray(numbers, size, checkIfEven);

	return EXIT_SUCCESS;
}

void traverseArray(int* array, int size, Callback callback) {
	for (size_t i = 0; i < size; i++) {
		callback(array[i]);
	}
}

void printElement(int element) {
	printf("%d\n", element);
}

void doubleElement(int element) {
	printf("%d doubled is %d\n", element, element * 2);
}

void checkIfEven(int element) {
	if (element % 2 == 0) {
		printf("%d is even.\n", element);
	}
	else {
		printf("%d is odd.\n", element);
	}
}