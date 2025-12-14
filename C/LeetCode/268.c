#include <stdio.h>
#include <stdlib.h>

int main(){
    return 0;
}

int missingNumber(int* nums, int numsSize) {
    long sum = 0;

    for(int i = 0; i < numsSize; i++){
        sum += i - nums[i];
    }
    sum += numsSize;

    return (int)(sum);
}