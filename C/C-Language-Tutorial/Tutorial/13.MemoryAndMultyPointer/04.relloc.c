// 企业案例：realloc函数与释放
#include <stdio.h>
#include <stdlib.h>

void printBudgets(double* budgets, int size);

int main04(void) {
	// 动态调整部门预算列表
	int size = 3; // 初始的预算项数

	double* budgets = (double*)malloc(size * sizeof(double));
	if (budgets == NULL) {
		perror("Failed to allocate initial busgets.");
		return EXIT_FAILURE;
	}

	// 假设的初始预算分配
	budgets[0] = 10000;
	budgets[1] = 20000;
	budgets[2] = 15000;

	printBudgets(budgets, size);

	// 新的一年，需要增加预算
	int newSize = 5;
	double* newBudgets = (double*)realloc(budgets, newSize * sizeof(double));

	if (newBudgets == NULL) {
		perror("Failed to reallocate initial busgets.");
		free(budgets);
		return EXIT_FAILURE;
	}

	budgets = newBudgets; // 更新指针

	budgets[3] = 12000;
	budgets[4] = 18000;

	printBudgets(budgets, newSize);


	free(budgets);

	return EXIT_SUCCESS;
}

void printBudgets(double* budgets, int size) {
	printf("Current budgets:\n");
	for (size_t i = 0; i < size; i++) {
		printf("Department %zu: $%.f\n", i + 1, budgets[i]);
	}
}