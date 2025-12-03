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
    int left = 0;
    int right = numsSize - 1;

    while(left <= right){
        // 防止溢出
        int mid = left + (right - left) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return left;
}