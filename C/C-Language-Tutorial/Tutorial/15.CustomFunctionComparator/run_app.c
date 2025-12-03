// 企业案例：自定义函数处理比较器

// 5.排序算法中的自定义比较函数
// 
// 设计概述：
// 1.抽象层
// 2.策略模式
// 3.模块化
// 4.安全性和跨平台
#include <stdio.h>
#include <stdlib.h>

#include "compare.h"
#include "sort.h"
#include "person.h"

int main(void) {
	int intArr[] = { 1, 43, 542, 9, 43, 450259, 314, 43 };
	int intArrCount = sizeof(intArr) / sizeof(intArr[0]);

	const char* stringArr[] =
	{ "Google", "Microsoft", "ByteDance", "Apple", "Tecent" };
	int stringArrCount = sizeof(stringArr) / sizeof(stringArr[0]);

	genericSort(intArr, intArrCount, sizeof(int), intCompare, NULL);
	genericSort(stringArr, stringArrCount, sizeof(char*), stringCompare, NULL);

	puts("intArr[] = ");
	for (size_t i = 0; i < intArrCount; i++) {
		printf("%d ", intArr[i]);
	}
	printf("\n");

	puts("\nstringArr[] = ");
	for (size_t i = 0; i < stringArrCount; i++) {
		printf("%s ", stringArr[i]);
	}
	printf("\n");

	Person personArr[] = {
		{"Ace", 21},
		{"Tom", 24},
		{"Jack", 18},
		{"Jerry", 28},
		{"Dave", 60},
		{"Kim", 37}
	};

	size_t peopleCount = sizeof(personArr) / sizeof(personArr[0]);

	CompareFunc compareFunctions[] = { compareByName, compareByAge };

	int compareChoice = 1;	// 0 for name, 1 for age

	genericSort(personArr, peopleCount, sizeof(Person), compareFunctions[compareChoice], NULL);

	puts("\npersonArr[] = ");
	for (size_t i = 0; i < peopleCount; i++) {
		printf("%s, %d\n", personArr[i].name, personArr[i].age);
	}
	printf("\n");

	return EXIT_SUCCESS;
}