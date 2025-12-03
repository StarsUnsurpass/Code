#include <stdio.h>
#include <stdlib.h>

int main(void){
    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int current = nums1Size - 1;

    for(; i >= 0 && j >= 0;){
        if(nums1[i] <= nums2[j]){
            nums1[current] = nums2[j];
            j--;
            current--;
        }
        else{
            nums1[current] = nums1[i];
            i--;
            current--;
        }
    }

    while(j >= 0){
        nums1[current] = nums2[j];
        current--;
        j--;
    }
}