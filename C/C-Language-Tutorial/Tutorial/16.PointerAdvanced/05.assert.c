// assert断言
// 如果为真继续执行，如果为假则终止
// 开发过程中捕获错误
// release不生效
// 不适用于处理运行时的错误情况
// 发布后将所有断言注释掉，太繁杂
// #define NDEBUG可禁用断言
// 验证可变参是否满足预期条件
// 前置条件和后置条件验证，验证函数开始和结束时状态
// 用printf一点点输出太乱
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int findMaximun(int* arr, int length);

void processImage(int weight, int height);

double calc(int quantity) {
	assert(quantity > 0);

	double discount = 0.0;

	if (quantity >= 50) {
		discount = 0.5;
	}
	else if (quantity >= 20) {
		discount = 0.2;
	}
	else if (quantity >= 10) {
		discount = 0.1;
	}

	assert(discount >= 0.0 && discount <= 0.5);

	return discount;
}

int main(void) {
	/*int a = 5;

	assert(a == 5);

	a = 3;

	assert(a == 5);

	puts("Hello");*/

	/*int numbers[] = { 1, 4, 5, 3, 2, 7, 8, 5 };

	int max = findMaximun(numbers, sizeof(numbers) / sizeof(numbers[0]));

	printf("The maximum number is %d\n", max);

	findMaximun(NULL, 0);*/

	/*processImage(1024, 768);

	//假设下面的w和h是通过其他函数，甚至是数组、指针传递的，那这个时候，是看不到它们的值小于50

	int w = 50, h = 50;
	processImage(w, h);

	return EXIT_SUCCESS;*/

	int quantity = 25;
	double discount = calc(quantity);

	printf("The discount for %d items is %.2f%%.\n", quantity, discount * 100);

	// 有时候代码是传递过来的，看不到quantity的值
	quantity = -5;
	discount = calc(quantity);
	printf("The discount for %d items is %.2f%%.\n", quantity, discount * 100);

	return EXIT_SUCCESS;
}

void processImage(int width, int height) {
	assert(width > 50 && width < 10000);
	assert(height > 50 && height < 10000);

	if (width > 50 && height > 50) {
		printf("Processing an image of size %d x %d pixels.\n", width, height);
	}
}

int findMaximun(int* arr, int length) {
	assert(arr != NULL && length > 0);

	int max = arr[0];

	for (size_t i = 0; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}