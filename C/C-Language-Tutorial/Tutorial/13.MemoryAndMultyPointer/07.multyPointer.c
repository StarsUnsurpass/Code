// 多级指针（指向指针的指针）
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	float price;
} Product;

// 返回一个Product地址
Product* create_product1(int id, float price);

void update_by_wholesaler(Product* product, int new_id, float new_price);
void update_by_retailer(Product* product, int new_id, float new_price);

int main07(void) {
	// int a = 10; 
	// 一个普通的int变量

	// int* ptr = &a; 
	// 一个指向int变量a的指针

	// ptr->a
	// ptr是一个指针，一个指针是保存了一个变量的地址

	// int** pptr = &ptr; 
	// 一个指向指针ptr的地址

	/*Product* product1 = create_product(1, 10.0);
	printf("Product1 ID: %d, Price: %.2f\n", product1->id, product1->price);

	Product* product2 = create_product(2, 20.0);
	printf("Product2 ID: %d, Price: %.2f\n", product2->id, product2->price);

	printf("Again=======================\n");
	printf("Product1 ID: %d, Price: %.2f\n", product1->id, product1->price);*/


	Product* product = create_product1(1, 10.0);
	printf("Product ID: %d, Price: %.2f\n", product->id, product->price);

	update_by_wholesaler(product, 18, 105);
	printf("update_by_wholesaler\tProduct ID: %d, Price: %.2f\n", product->id, product->price);

	update_by_retailer(product, 30, 135);
	printf("update_by_retailer\tProduct ID: %d, Price: %.2f\n", product->id, product->price);



	free(product);

	

	return EXIT_SUCCESS;
}

Product* create_product1(int id, float price) {
	// 错误写法
	/*
	Product p; // 被分配在栈上，是一个局部变量
	p.id = id;
	p.price = price;
	printf("Inside----ID: %d, Price: %.2f, Address: %p\n", p.id, p.price, (void*) & p);

	return &p;
	*/

	Product* product = (Product*)malloc(sizeof(Product));

	if (product == NULL) {
		perror("Failed to allocate memory!");
		exit(EXIT_FAILURE);
	}

	product->id = id;
	product->price = price;

	printf("Inside----ID: %d, Price: %.2f, Address: %p\n", product->id, product->price, (void*)product);

	return product;
}

void update_by_wholesaler(Product* product, int new_id, float new_price) {
	product->id = new_id;
	product->price = new_price;
}

void update_by_retailer(Product* product, int new_id, float new_price) {
	product->id = new_id;
	product->price = new_price;
}