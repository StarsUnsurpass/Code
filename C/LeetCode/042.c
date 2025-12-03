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

    while (left < right) {
        while (height[left] == 0 && left < right) {
            left++;
        }

        while (height[right] == 0 && left < right) {
            right--;
        }

        if (height[left] == 0 || height[right] == 0) {
            break;
        }

        int i = left;

        while (i <= right) {
            if (height[i]) {
                height[i]--;
            }
            else {
                res++;
            }
            i++;
        }
    }

    return res;
}