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
    int left = 0;
    int right = heightSize - 1;

    while(left < right){
        int h_left = height[left];
        int h_right = height[right];
        int min_h = h_left < h_right ? h_left : h_right;
        
        int size = (right - left) * min_h;
        if(size > res){
            res = size;
        }

        if(h_left < h_right){
            left++;
        } else {
            right--;
        }
    }

    return res;
}