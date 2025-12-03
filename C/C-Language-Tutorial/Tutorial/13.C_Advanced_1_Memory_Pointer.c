#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct Character {
	char* name;
	int level;
	int hp;
} Character;

typedef struct Employee {
	char* name;
	int* taskList;
	int taskCount;
} Employee;

typedef struct {
	int id;
	float price;
	const char* manufacturer;
} Product;



void printBudgets(double* budgets, int size);

Character* create_character(const char* name, int level, int hp);

void free_character(Character* character);

Employee* create_employee(const char* name, int taskCount);

void free_employee(Employee* employee);

Product* create_product(int id, float price, const char* manufacturer);

void update_by_wholesaler(Product* product, int new_id, float new_price);

void update_by_retailer(Product* product, int new_id, float new_price);

const char* get_manufacturer_info(Product** product_ptr);



int main7(void) {
	//传统数组的问题
	//1.灵活性低，整个程序走下来，都依赖预设编译前的大小
	//2.内存的浪费与安全隐患
	//3.应用受限
	//动态内存分配
	//1.处理可变大小的数据
	//2.高效的数据结构
	//3.资源优化


	//栈内存和堆内存的对比
	/*
	计算机操作系统内存的管理机制有两种不同的存储区域
	由 分配机制、生命周期、访问速度、用途区分 决定
	编译、运行

	1.栈内存（Stack Memory）
	int number; 4bytess
	int arr[4]; 编译时确定长度
	a.自动管理机制：函数调用时，局部变量会被分配到栈上，当函数返回时，局部变量全部销毁释放
	b.速度快：栈内存的分配和访问速度通常要比堆内存快，是一种线性数据结构
	c.大小有限制：栈的大小，在程序启动时就已经确定，如果栈的内存空间被耗尽，就意味着崩溃（栈溢出）
	d.函数的局部变量、函数参数、函数调用的返回地址

	2.堆内存（Heap Memory）
	a.动态管理：malloc, calloc, realloc, free
	b.速度相对于堆有点慢，需要在内存中寻找足够大的连续空间块
	c.大小灵活：堆的大小通常受到可用系统内存的限制，而非堆本身的限制，它能够支持动态按需分配大量内存
	d.需要动态内存分配的全局变量
	*/


	//malloc函数动态内存分配的使用与释放
	//静态数组的声明和初始化
	//编译时就已经确定了，整个数组的大小和生命周期连同作用域，都一起决定了
	//分配到栈上
	/*int static_arr[5] = { 1, 2, 3, 4, 5 };
	printf("静态数组的内容：\n");
	for (size_t i = 0; i < 5; i++) {
		printf("%d ", static_arr[i]);
	}
	printf("\n");*/
	//动态内存分配
	//分配到堆上
	//malloc函数返回void*指针
	//void*在C语言中用于泛型编程
	//堆内存要手动释放，因为不是简单的局部变量那么简单，局部变量会在函数执行完之后手动释放，而堆不会
	/*int* dynamic_arr = (int*)malloc(5 * sizeof(int));
	if (dynamic_arr == NULL) {
		perror("动态数组分配失败");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 5; i++) {
		dynamic_arr[i] = (i + 1) * 10;
	}
	puts("动态数组的内容：");
	for (size_t i = 0; i < 5; i++) {
		printf("%d ", dynamic_arr[i]);
	}*/


	//realloc函数与释放
	/*int size = 3;

	double* budgets = (double*)malloc(size * sizeof(double));
	if (budgets == NULL) {
		perror("Failed to allocate budgets");
		return EXIT_FAILURE;
	}

	budgets[0] = 10000;
	budgets[1] = 20000;
	budgets[2] = 30000;

	printBudgets(budgets, size);

	int newSize = 5;
	double* newBudgets = (double*)realloc(budgets, newSize * sizeof(double));

	if (newBudgets == NULL) {
		perror("Failed to reallocate budgets");
		free(budgets);
		return EXIT_FAILURE;
	}

	budgets = newBudgets;

	budgets[3] = 40000;
	budgets[4] = 50000;

	printBudgets(budgets, newSize);

	free(budgets);

	return EXIT_SUCCESS;*/


	//malloc与结构体的使用以及防止内存泄漏
	/*Character* hero = create_character("Hello", 1, 100);

	if (hero == NULL) {
		return EXIT_FAILURE;
	}

	printf("hero's name is: %s\nlevel is: %d\nhp is: %lf\n", hero->name, hero->level, hero->hp);

	free_character(hero);

	return EXIT_SUCCESS;*/


	//calloc函数
	//不仅可以分配内存，还可以将所有位置设置为0
	/*Employee* developer = create_employee("Ace", 5);

	if (developer == NULL) return EXIT_FAILURE;

	developer->taskList[0] = 101;

	printf("Assigned Task ID for %s: %d\n", developer->name, developer->taskList[0]);
	printf("Assigned Task ID for %s: %d\n", developer->name, developer->taskList[1]);

	free_employee(developer);

	return EXIT_SUCCESS;*/


	//多级指针
	/*int a = 10;
	int* ptr = &a;
	int** pptr = &ptr;*/


	//多级指针的用途
	//*解引
	/*Product* product1 = create_product(1, 10.0);

	printf("Product1 ID: %d, Price: %.2f\n", product1->id, product1->price);

	Product* product2 = create_product(2, 20.0);

	printf("Product2 ID: %d, Price: %.2f\n", product2->id, product2->price);

	printf("Again----Product1 ID: %d, Price: %.2f\n", product1->id, product1->price);*/
	/*Product* product = create_product(1, 10.0, "my_factory");

	printf("Factory---Product ID: %d, Price: %.2f, Manufacturer: %s\n", product->id, product->price, product->manufacturer);

	update_by_wholesaler(product, 222, 15.0);

	printf("update_by_wholesaler\t --- Product ID: %d, Price: %.2f\n", product->id, product->price);

	update_by_retailer(product, 333, 20.0);

	printf("update_by_retailer\t --- Product ID: %d, Price: %.2f\n", product->id, product->price);

	Product* wholesaler_product = product;

	Product** retailer_product = &wholesaler_product;

	printf("Retailer---Product ID: %d, Price: %.2f, Manufacturer: %s\n", (*retailer_product)->id,
		(*retailer_product)->price, (*retailer_product)->manufacturer);

	printf("Retailer---Product ID: %d, Price: %.2f, Manufacturer: %s\n", (**retailer_product).id,
		(**retailer_product).price, (**retailer_product).manufacturer);

	const char* manufacturer_info = get_manufacturer_info(retailer_product);

	printf("Retailer contacted factory through wholesaler: Manufacturer: %s\n", manufacturer_info);

	free(product);*/


	
	





	return 0;
}

const char* get_manufacturer_info(Product** product_ptr) {
	return (*product_ptr)->manufacturer;
	//return (**product_ptr).manufacturer;
}

void update_by_retailer(Product* product, int new_id, float new_price) {
	product->id = new_id;
	product->price = new_price;
}

void update_by_wholesaler(Product* product, int new_id, float new_price) {
	product->id = new_id;
	product->price = new_price;
}

Product* create_product(int id, float price, const char* manufacturer) {
	//错误写法
	/*Product p;
	p.id = id;
	p.price = price;

	printf("Inside----ID: %d, Price: %.2f, Address: %p\n", p.id, p.price, (void*)&p);

	return &p;*/

	Product* product = (Product*)malloc(sizeof(Product));

	if (product == NULL) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	product->id = id;
	product->price = price;
	product->manufacturer = manufacturer;

	printf("Inside----ID: %d, Price: %.2f, Address: %p\n", product->id, product->price, (void*)product);

	return product;
}

void free_employee(Employee* employee) {
	if (employee != NULL) {
		free(employee->name);
		free(employee->taskList);
		free(employee);
	}
}

Employee* create_employee(const char* name, int taskCount) {
	Employee* new_employee = (Employee*)malloc(sizeof(Employee));

	if (new_employee == NULL) {
		perror("Failed to allocate memory for new employee");
		return NULL;
	}

	new_employee->name = (char*)malloc(strlen(name) + 1);

	if (new_employee->name == NULL) {
		perror("Failed to allocate memory for new employee name");
		free(new_employee);
		return NULL;
	}

	strcpy_s(new_employee->name, strlen(name) + 1, name);

	new_employee->taskCount = taskCount;
	new_employee->taskList = (int*)calloc(taskCount, sizeof(int));

	if (new_employee->taskList == NULL) {
		perror("Failed to allocate memory for task list");
		free(new_employee->name);
		free(new_employee);
		return NULL;
	}

	return new_employee;
}

void free_character(Character* character) {
	if (character != NULL) {
		free(character->name); // 释放名字字符串占用的内存
		free(character);
	}
}

Character* create_character(const char* name, int level, int hp) {
	Character* new_character = (Character*)malloc(sizeof(Character));

	if (new_character == NULL) {
		perror("Failed to allocate memory for new character");
		return NULL;
	}

	new_character->name = (char*)malloc(strlen(name) + 1); // malloc之后紧跟一个卫语句

	if (new_character->name == NULL) {
		perror("Failed to allocate memory for new character name");
		free(new_character); // 防止内存泄漏
		return NULL;
	}

	strcpy_s(new_character->name, strlen(name) + 1, name);
	new_character->level = level;
	new_character->hp = hp;
}

void printBudgets(double* budgets, int size) {
	printf("Current budget:\n");
	for (size_t i = 0; i < size; i++) {
		printf("Department %zd: $%.2f\n", i + 1, budgets[i]);
	}
}