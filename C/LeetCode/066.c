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
    // returnSize 是一个指针参数，需要通过解引用 *returnSize 来设置它的值

    int sign = 0;

    for(int i = digitsSize - 1; i >= 0; i--){
        int tmp = digits[i] + 1;
        sign = tmp / 10;
        digits[i] = tmp % 10;

        // 没有进位，提前结束
        if(sign == 0){
            break;
        }
    }
    *returnSize = digitsSize;

    if(sign == 0){
        return digits;
    }
    else{
        // 先解引用，然后值加1
        (*returnSize)++;
        int* newDigits = (int*)realloc(digits, sizeof(int) * *returnSize);
        for(size_t i = *returnSize - 1; i > 0; i--){
            newDigits[i] = newDigits[i - 1];
        }
        newDigits[0] = 1;

        return newDigits;
    }
}