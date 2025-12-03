#include <stdio.h>
#include <stdlib.h>

int main(void){
    return 0;
}

int majorityElement(int* nums, int numsSize) {
    int cnt = 0;
    int res;

    for(int i = 0; i < numsSize; i++){
        if(cnt == 0){
            res = nums[i];
        }
        cnt += (nums[i] == res) ? 1 : -1;
    }

    return res;
}