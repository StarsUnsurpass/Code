#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize);

int main(void){
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixSize = sizeof(matrix) / sizeof(int);
    int matrixColSize = sizeof(matrix[0]) / sizeof(int);
    int matrixRowSize = sizeof(matrixSize) / sizeof(matrixColSize);

    // 创建临时的指针数组（编译时完成，不占用额外运行时内存）
    int* temp_rows[] = {matrix[0], matrix[1], matrix[2]};

    puts("Before exchange:");
    for(size_t i = 0; i < matrixColSize; i++){
        for(size_t j = 0; j < matrixColSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    rotate(temp_rows, matrixSize, &matrixColSize);

    puts("After exchange:");
    for(size_t i = 0; i < matrixColSize; i++){
        for(size_t j = 0; j < matrixColSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp = 0;

    for(size_t i = 0; i < *matrixColSize; i++){
        for(size_t j = 0; j < *matrixColSize / 2; j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][*matrixColSize - 1 - j];
            matrix[i][*matrixColSize - 1 - j] = temp;
        }
    }

    for(size_t i = 0; i < *matrixColSize - 1; i++){
        for(size_t j = 0; j < *matrixColSize - 1 -i; j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[*matrixColSize - 1 - j][*matrixColSize - 1 - i];
            matrix[*matrixColSize - 1 - j][*matrixColSize - 1 - i] = temp;
        }
    }
}