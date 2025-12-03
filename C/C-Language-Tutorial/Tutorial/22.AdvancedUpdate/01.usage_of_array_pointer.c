// 再谈数组指针的用途
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

// 传递过来的数组列数已经确定
void print_matrix(int(*matrix)[3], int rows);
// void p2(int matrix[][3], int rows);
// void p3(int matrix, int rows, int cols);	// 一维数组模拟二维数组
// void p4(int** matrix, int rows, int cols);	// 动态二维数组

void flip_image(int (*image)[COLS], int rows, int cols);

int main01(void) {
	int arr[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	// 对于一个二维数组arr[m][n]，存储是以一维形式展开的：
	// arr[i][j] = *(arr + i * n + j)
	// arr是一个指向二维数组首地址的指针
	// i 行索引
	// j 列索引
	// n 每行的列数
	// arr[1][2] = *(arr + 1 * 3 + 2) = *(arr + 5)

	// 数组指针 Pointer to Array
	int (*ptr)[3] = arr; // ptr指向二维数组的第一行
	// 1.ptr指向的是一个二维数组的行首地址
	// 2.可以把二维数组的每一行当作一个一维数组来处理
	// 3.按行解决问题，每行多个元素
	// (*ptr)[j]，意味着ptr定位到具体的行，然后[j]定位到具体的列

	printf("%d\n", (*ptr)[1]);
	
	ptr++;

	printf("%d\n", (*ptr)[1]);

	print_matrix(arr, 2);








	return EXIT_SUCCESS;
}

void print_matrix(int(*matrix)[3], int rows) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < 3; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void flip_image(int (*image)[COLS], int rows, int cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols / 2; j++) {
			// 交换对称列
			int temp = image[i][j];
			// 镜像索引（symmetric index）
			image[i][j] = image[i][cols - 1 - j];
			image[i][cols - 1 - j] = temp;
		}
	}
}