#include <stdio.h>
#include <stdlib.h>

int main(void){
    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int current = m + n - 1;  // 直接用 m+n-1 更清晰
    
    // 合并两个数组
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {  // 可以省略等号情况
            nums1[current--] = nums1[i--];
        } else {
            nums1[current--] = nums2[j--];
        }
    }
    
    // 只需要处理 nums2 剩余元素
    // nums1 剩余元素已经在正确位置,无需移动
    while (j >= 0) {
        nums1[current--] = nums2[j--];
    }
}