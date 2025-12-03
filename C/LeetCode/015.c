#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(void){
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    int returnColumnSize = 0;

    return EXIT_SUCCESS;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if(numsSize == 3){
        if(nums[0] + nums[1] + nums[2] == 0){
            return nums;
        }
        return NULL;
    }

    
}