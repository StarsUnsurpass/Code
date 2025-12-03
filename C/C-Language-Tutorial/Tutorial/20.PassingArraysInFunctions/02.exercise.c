// 第二维大小不能省略
// int sum(int arr[][4], int size);
// int sum(int (*)[4], int size);
// 数组作为参数传递必须传递size
// const确保数组在传递过程中不会被转换，保证原始性

// 1.数组作为函数参数：传递（大）数据集，共享内存数据
// 2.函数指针：多态性，回调函数，动态调用

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4
#define MAX_NAME 50

typedef struct {
	char name[MAX_NAME];
	int age;
} Person;

// static void print_2d_array(int rows, int cols, int [ROWS][COLS]);
static void print_2d_array(int rows, int cols, int(*arr)[COLS]);

static void modify_person_array(Person* people, size_t size);

static int compare_persons(const void* a, const void* b);

static void greet(const char* name);

static void farewell(const char* name);

typedef void (*MessageFunc)(const char*);

int main02(void) {
	int matrix[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	printf("2D Array:\n");
	print_2d_array(ROWS, COLS, matrix);
	printf("\n");

	Person people[] = {
		{"Tom", 20},
		{"Jack", 22},
		{"Jerry", 18}
	};

	size_t people_num = sizeof(people) / sizeof(people[0]);

	printf("Before modification:\n");
	for (size_t i = 0; i < people_num; i++) {
		printf("%s:\t %d\n", people[i].name, people[i].age);
	}

	modify_person_array(people, people_num);

	printf("\nAfter modification:\n");
	for (size_t i = 0; i < people_num; i++) {
		printf("%s:\t %d\n", people[i].name, people[i].age);
	}

	qsort(people, people_num, sizeof(Person), compare_persons);
	printf("\nAfter sorting by age:\n");
	for (size_t i = 0; i < people_num; i++) {
		printf("%s:\t %d\n", people[i].name, people[i].age);
	}

	MessageFunc messages[] = { greet, farewell };

	const char* name = "David";

	printf("\nFunction pointer array demonstration:\n");
	for (size_t i = 0; i < sizeof(messages) / sizeof(messages[0]); i++) {
		messages[i](name);
	}



	return EXIT_SUCCESS;
}

static void print_2d_array(int rows, int cols, int(*arr)[COLS]) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
}

static void modify_person_array(Person* people, size_t size) {
	for (size_t i = 0; i < size; i++) {
		people[i].age++;
	}
}

static int compare_persons(const void* a, const void* b) {
	return ((const Person*)a)->age - ((const Person*)b)->age;
}

static void greet(const char* name) {
	printf("Hello, %s!\n", name);
}

static void farewell(const char* name) {
	printf("Goodbye, %s!\n", name);
}
