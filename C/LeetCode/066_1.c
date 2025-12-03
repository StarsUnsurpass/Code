#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main(void){
    int digits[] = {1, 2, 3, 4, 9};

    int digitsSize = sizeof(digits) / sizeof(int);
    int returnSize = 0;

    puts("Before process:");
    for(int i = 0; i < digitsSize; i++){
        printf("%d ", digits[i]);
    }
    printf("\n");

    puts("After process:");
    int* newDigits = plusOne(digits, digitsSize, &returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%d ", newDigits[i]);
    }
    printf("\n");

    // 释放内存
    free(newDigits);

    return EXIT_SUCCESS;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 不全为9
    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] < 9){
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    // 全为9
    *returnSize = digitsSize + 1;
    int* newDigits = (int*)malloc(sizeof(int*) * (*returnSize));
    newDigits[0] = 1;
    for(int i = 1; i < *returnSize; i++){
        newDigits[i] = 0;
    }

    return newDigits;
}