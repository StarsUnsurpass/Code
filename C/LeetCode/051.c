#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n = 0;
    int returnSize = 0;
    int returnColumnSizes = 0;

    return EXIT_SUCCESS;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char* arrayRows = malloc(sizeof(char) * n);
    char** array = malloc(sizeof(char) * n * n);

    returnSize = 0;

    for(size_t i = 0; i < n; i++){
        arrayRows[i] = array[i * n];
    }

    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            array[i][j] = '.';
        }
    }

    for(size_t i = 0; i < n; i++){
        
    }
}