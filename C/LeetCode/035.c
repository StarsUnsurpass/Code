#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target);

int main(){
    int nums[4] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);

    int target = 2;

    int res = searchInsert(nums, numsSize, target);

    printf("The result is: %d\n", res);

    return EXIT_SUCCESS;
}

int searchInsert(int* nums, int numsSize, int target) {
    if(nums[0] > target) return 0;
    for(size_t i = 0; i < numsSize; i++){
        if(nums[i] == target){
            return i;
        }
        
        /*
        虽然你加了 i < numsSize - 1 这个条件，但是C语言的逻辑运算符短路求值是从左到右的。当 i 等于 numsSize - 1 时：
        nums[i] < target 为 true
        接着执行 nums[i + 1] > target，此时 i + 1 = numsSize，已经越界了！
        只有在前两个条件都判断完后，才会检查 i < numsSize - 1
        */
        // if(nums[i] < target && nums[i + 1] > target && i < numsSize - 1){
        if(i < numsSize - 1 && nums[i] < target && nums[i + 1] > target){    
            return i + 1;
        }
    }

    return numsSize;
}