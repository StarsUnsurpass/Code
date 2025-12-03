#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int heightSize);

int main(void){
    //int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightSize = sizeof(height) / sizeof(int);

    int size = trap(height, heightSize);

    printf("%d\n", size);

    return 0;
}

int trap(int* height, int heightSize) {
    int res = 0;

    int left = 0;
    int right = heightSize - 1;
    int left_max = 0;
    int right_max = 0;

    while (left < right) {
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] > left_max){
                    left_max = height[left];
                }
                else{
                    res += left_max - height[left];
                }

                left++;
            }
            else{
                if(height[right] > right_max){
                    right_max = height[right];
                }
                else{
                    res += right_max - height[right];
                }

                right--;
            }
        }
    }

    return res;
}