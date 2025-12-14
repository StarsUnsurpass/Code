#include <stdio.h>
#include <stdlib.h>

int main(){
    return 0;
}

int missingNumber(int* nums, int numsSize) {
    int res = numsSize;

    for(int i = 0; i < numsSize; i++){
        res ^= nums[i] ^ i;
    }

    return res;
}