// 软件工程：组合、聚合、嵌套、构造、析构
// ————结构体指针的高级应用
// 组合 Composition 包含 Containment
// 聚合 Aggregation
// 嵌套 Nesting
// 构造 Constructor
// 析构
// 动态数组 Dynamic Array
// 自引用 Self_Referencing
// 链式结构 Linked Structure
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	SUCCESS = 0,
	MEMORY_ERROR,
	INVALID_PARAMS,
	DUPLICATE_ID,
	NOT_FOUND
} ErrorCode;

typedef struct {
	int id;
	char* title;
	double price;
} Book;

typedef struct {
	// Book books; -> 嵌套 Nesting
	// 聚合 Aggregation 引入外部数据
	Book* books;	// 组合 Composition 包含 Containment
	size_t count;
	size_t capacity;
} Library;

// 构造函数 Constructor
Library create_library(size_t initial_capacity, ErrorCode* error) {
	Library lib = { 0 };

	if (initial_capacity == 0) {
		*error = INVALID_PARAMS;
		return lib;
	}

	lib.books = (Book*)malloc(initial_capacity * sizeof(Book));
	if (!lib.books) {
		*error = MEMORY_ERROR;
		return lib;
	}

	lib.count = 0;
	lib.capacity = initial_capacity;

	*error = SUCCESS;
	return lib;
}

ErrorCode add_book(Library* lib, int id, const char* title, double price) {
	if (!lib || !title || price <= 0) {
		return INVALID_PARAMS;
	}

	for (size_t i = 0; i < lib->count; i++) {
		if (lib->books[i].id == id) {
			return DUPLICATE_ID;
		}
	}

	// 是否需要扩容
	if (lib->count >= lib->capacity) {
		size_t new_capacity = lib->capacity * 2;
		Book* temp = (Book*)realloc(lib->books, new_capacity * sizeof(*lib->books));
		if (!temp) {
			return MEMORY_ERROR;
		}

		lib->books = temp;
		lib->capacity = new_capacity;
	}

	// 分配书名的内存
	char* new_title = (char*)malloc(strlen(title) + 1);
	if (!new_title) {
		return MEMORY_ERROR;
	}
	strcpy(new_title, title);

	lib->books[lib->count].id = id;
	lib->books[lib->count].title = new_title;
	lib->books[lib->count].price = price;
	lib->count++;

	return SUCCESS;
}

Book* find_book(const Library* lib, int id, ErrorCode* error) {
	if (!lib) {
		*error = INVALID_PARAMS;
		return NULL;
	}

	for (size_t i = 0; i < lib->count; i++) {
		if (lib->books[i].id == id) {
			*error = SUCCESS;
			return &lib->books[i];
		}
	}

	*error = NOT_FOUND;
	return NULL;
}

void print_library(const Library* lib) {
	if (!lib) {
		printf("错误：无效的图书馆！\n");
		return;
	}

	printf("\n图书馆藏书数量：%zu\n", lib->count);
	for (size_t i = 0; i < lib->count; i++) {
		printf("书籍 #%zu\n", i + 1);
		printf("	ID:%d\n", lib->books[i].id);
		printf("	Title:%s\n", lib->books[i].title);
		printf("	Price:%lf\n", lib->books[i].price);
		printf("========================\n");
	}
}

void free_library(Library* lib) {
	if (!lib || !lib->books) {
		return;
	}

	for (size_t i = 0; i < lib->count; i++) {
		free(lib->books[i].title);
		lib->books[i].title = NULL;
	}
	free(lib->books);

	lib->books = NULL;
	lib->count = 0;
	lib->capacity = 0;
}

int main(void) {
	ErrorCode error;

	Library lib = create_library(2, &error);

	if (error != SUCCESS) {
		printf("创建图书馆失败，错误码：%d\n", error);
		return 1;
	}

	error = add_book(&lib, 1, "C++", 999);
	if (error != SUCCESS) {
		printf("添加图书失败，错误码：%d\n", error);
		free_library(&lib);
		return 1;
	}

	error = add_book(&lib, 2, "Java", 888);
	if (error != SUCCESS) {
		printf("添加图书失败，错误码：%d\n", error);
		free_library(&lib);
		return 1;
	}

	error = add_book(&lib, 3, "Python", 18);
	if (error != SUCCESS) {
		printf("添加图书失败，错误码：%d\n", error);
		free_library(&lib);
		return 1;
	}

	print_library(&lib);

	printf("\ncapacity: %zu\n", lib.capacity);

	free_library(&lib);

	return EXIT_SUCCESS;
}