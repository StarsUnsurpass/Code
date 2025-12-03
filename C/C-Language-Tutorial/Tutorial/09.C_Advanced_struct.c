#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>




typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char name[50];
	int id;
	float score;
} Student;

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	char street[50];
	char city[50];
	char country[50];
} Address;

typedef struct {
	char name[50];
	int age;
	Address address;
} Person;

typedef enum {
	MONDAY,
	TUESDAYM,
	WEDNESDAYM,
	THUISDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
} Weekday;


typedef union {
	int int_value;
	float float_value;
	char* string_value;
} Data;

typedef enum {
	INT,
	FLOAT,
	STRING
} DataType;

typedef struct {
	DataType type;
	Data data;
} TypeData;






void print_stu(Student stu);

void update_score_by_value(Student stu, float new_score);
void update_score_by_reference(Student* stu, float new_score);

Point get_point(void);

void print_data(TypeData* typed_data);

int main2(void) {
	//结构体
	/*struct Date {
		int day;
		int onth;
		int year;
	};

	struct Person {
		char name[50];
		int age;
		float height;
	};

	struct Date todat = { 18, 10, 2025 };

	struct Person me = { "ace", 21, 177.0};*/


	//创建结构体变量与访问方式
	//结构体一般是全局，项目开发时一般单独一个文件
	//通过.去访问成员或指针
	/*Date today = { 18, 10, 2025 };

	printf("Today's date is: %d-%d-%d\n", today.year, today.month, today.day);

	Date* date_ptr = &today;

	printf("Accessed via pointer: %d-%d-%d\n", date_ptr->year, date_ptr->month, date_ptr->day);*/


	//匿名结构体、函数参数为结构体
	/*Student stu = { "Tom", 101, 97.5 };

	puts("Before update:\n");

	print_stu(stu);

	update_score_by_value(stu, 100);

	puts("After update value:\n");

	print_stu(stu);

	update_score_by_reference(&stu, 99);

	puts("After update reference:\n");

	print_stu(stu);*/


	//值语义初始结构体变量
	//从外部函数初始化一个结构体更安全
	/*Point my_point = get_point();
	Point your_point = get_point();
	Point jack = get_point();
	printf("Point: (%d, %d)\n", my_point.x, my_point.y);*/


	//结构体数组
	/*Point points[2] = {
		{1, 2}, {3, 4}
	};

	for (int i = 0; i < 2; i++) {
		printf("Point %d: (%d, %d)\n", i + 1, points[i].x, points[i].y);
	}*/


	//嵌套结构体
	/*Person me = {
		"Tom",
		21,
		{"ST", "SS", "CHINA"}
	};

	printf("Name: %s\n", me.name);
	printf("Address: %s, %s, %s\n", me.address.street, me.address.city, me.address.country);

	Person* ptr = &me;

	printf("Name: %s\n", ptr->name);
	printf("Address: %s, %s, %s\n", ptr->address.street, ptr->address.city, ptr->address.country);*/


	//Enumeration枚举
	//#define
	//可通过函数switch输出
	/*Weekday day = FRIDAY;
	printf("%d\n", day);
	printf("%d\n", SUNDAY);*/


	//Union联合
	//允许在相同的内存位置存储不同的数据类型
	//联合体的所有成员共享一块内存空间，大小等于其最大成员的大小
	//意味着在任一时刻，联合体只能存储一个成员的值
	//一个变量可能存储多种类型的数据，但是在一个给定的时刻，只是用其中一种的数据类型，可以节省内存
	/*TypeData data1 = { INT, {10} };
	TypeData data2 = { FLOAT, {3.14} };

	print_data(&data1);
	print_data(&data2);*/




	return 0;
}



void print_data(TypeData* typed_data) {
	switch (typed_data->type) {
	case INT:
		printf("Integer: %d\n", typed_data->data.int_value);
		break;
	case FLOAT:
		printf("Float: %f\n", typed_data->data.float_value);
		break;
	case STRING:
		printf("String: %s\n", typed_data->data.string_value);
		break;
	}
}

Point get_point(void) {
	Point p = { 10, 20 };
	return p;
}

void print_stu(Student stu) {
	printf("Student name: %s\n", stu.name);
	printf("Student id: %d\n", stu.id);
	printf("Student score: %.2f\n", stu.score);
}

void update_score_by_value(Student stu, float new_score) {
	stu.score = new_score;
}

void update_score_by_reference(Student* stu, float new_score) {
	stu->score = new_score;
}