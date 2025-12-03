#include <stdio.h>
#include <stdlib.h>

int* global_ptr;

void function() {
	int local = 5;

	int* local_ptr = &local; // 局部指针

	global_ptr = (int*)malloc(sizeof(int));
	*global_ptr = 10;

	printf("Inside function: local_ptr points to %d\n", *local_ptr);
}

int main01(void) {
	// 指针作用域和生命周期
	function();

	printf("Outside function: global_ptr points to %d\n", *global_ptr);

	free(global_ptr);

	return EXIT_SUCCESS;
}