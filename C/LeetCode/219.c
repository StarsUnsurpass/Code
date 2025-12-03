#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    return 0;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j <= i + k && j < numsSize; j++){
            if(nums[i] == nums[j]){
                return true;
            }
        }
    }

    return false;
}