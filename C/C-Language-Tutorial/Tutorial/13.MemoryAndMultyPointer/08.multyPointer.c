// 多级指针（指向指针的指针）
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	float price;
	const char* manufacturer;
} Product;

Product* create_product(int id, float price, const char* manufacturer);

const char* get_manufacturer_info(Product** product_ptr);

int main08(void) {
	Product* product = create_product(1, 10.0, "My Factory");
	printf("Factory---Product ID: %d, Price: %.2f, Factory: %s\n", product->id, product->price, product->manufacturer);

	// 批发商从工厂获取产品
	Product* wholesaler_product = product;

	// 零售商获取产品，并联系工厂
	Product** retailer_product = &wholesaler_product;
	// 解引两次
	printf("Retailer---Product ID: %d, Price: %.2f, Factory: %s\n", 
		(*retailer_product)->id, (*retailer_product)->price, (*retailer_product)->manufacturer);
	printf("Retailer---Product ID: %d, Price: %.2f, Factory: %s\n",
		(**retailer_product).id, (**retailer_product).price, (**retailer_product).manufacturer);

	const char* manufacturer_info = get_manufacturer_info(retailer_product);

	printf("Retailer contacted factory through wholesaler: Manufacturer: %s\n", manufacturer_info);


	free(product);



	return EXIT_SUCCESS;
}

Product* create_product(int id, float price, const char* manufacturer) {
	Product* product = (Product*)malloc(sizeof(Product));

	if (product == NULL) {
		perror("Failed to allocate memory!");
		exit(EXIT_FAILURE);
	}

	product->id = id;
	product->price = price;
	product->manufacturer = manufacturer;

	printf("Inside----ID: %d, Price: %.2f\n", product->id, product->price);

	return product;
}

const char* get_manufacturer_info(Product** product_ptr) {
	return (*product_ptr)->manufacturer;
	// return (**product_ptr).manufaacturer;
}