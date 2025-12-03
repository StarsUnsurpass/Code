#include <stdio.h>
#include <stdlib.h>

// 合并两个有序子数组 arr[left...mid] 和 arr[mid+1...right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    // 计算两个子数组的长度
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组来存放数据
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回 arr[left...right]
    i = 0;    // 初始化第一个子数组的索引
    j = 0;    // 初始化第二个子数组的索引
    k = left; // 初始化合并子数组的索引

    while (i < n1 && j < n2) {
        // 比较左右两个数组当前元素的大小，将较小的放入原数组
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 剩余的元素（如果有）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 剩余的元素（如果有）
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 释放临时数组的内存
    free(L);
    free(R);
}

// 归并排序的主函数
// left 是左索引，right 是右索引
void mergeSort(int arr[], int left, int right) {
    // 递归终止条件：当 left >= right，说明子数组只有一个元素或没有元素
    if (left < right) {
        // 找到中间点，防止溢出的写法
        int mid = left + (right - left) / 2;

        // 递归排序第一半
        mergeSort(arr, left, mid);
        // 递归排序第二半
        mergeSort(arr, mid + 1, right);

        // 合并刚刚排序好的两半
        merge(arr, left, mid, right);
    }
}

// 打印数组的辅助函数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函数测试
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("排序后的数组: \n");
    printArray(arr, arr_size);
    return 0;
}