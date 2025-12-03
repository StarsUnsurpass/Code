#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize);

int main(void){
    int height[] = {4, 3, 2, 1, 4};
    int heightSize = sizeof(height) / sizeof(int);

    int res = maxArea(height, heightSize);

    printf("%d\n", res);
}

int maxArea(int* height, int heightSize) {
    int res = 0;
    int size = 0;
    int left = 0;
    int right = heightSize - 1;

    while(left < right){
        size = (right - left) * ((height[left] < height[right]) ? height[left] : height[right]);
        if(size > res){
            res = size;
        }

        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }

    return res;
}