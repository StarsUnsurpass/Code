#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) ;

int main(void){
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};

    //&nums1 的类型是 int (*)[2]（指向数组的指针），而不是 int*
    //该直接传递 nums1 和 nums2（数组名会自动退化为指针）
    double res = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));

    printf("%lf\n", res);

    return EXIT_SUCCESS;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double res = 0;
    int arrSize = nums1Size + nums2Size;
    int* array = malloc(sizeof(int) * arrSize);
    int cnt1 = 0;
    int cnt2 = 0;

    //没有检查 cnt1 < nums1Size 和 cnt2 < nums2Size
    //当一个数组已经遍历完时，继续访问会导致未定义行为
    //正确的边界检查逻辑
    for(size_t i = 0; i < arrSize; i++){
        //边界检查必须在数组访问之前进行，利用短路求值
        //注意 cnt2 >= nums2Size 必须在前面，利用短路求值避免访问越界的 nums2[cnt2]
        if(cnt1 < nums1Size && (cnt2 >= nums2Size || nums1[cnt1] < nums2[cnt2])){
            array[i] = nums1[cnt1];
            cnt1++;
            continue;
        }

        array[i] = nums2[cnt2];
        cnt2++;
    }

    if(arrSize % 2 == 0){
        double num1 = array[arrSize / 2 - 1];
        double num2 = array[arrSize / 2];
        res = (num1 + num2) / 2;
        free(array);
        return res;
    }

    res = (double)array[arrSize / 2];
    free(array);
    return res;
}