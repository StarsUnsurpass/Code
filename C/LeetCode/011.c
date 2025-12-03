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
    int res = (height[0] <= height[1]) ? height[0] : height[1];
    int tmp = res;
    int min = height[0];

    for(size_t i = 0; i < heightSize - 1; i++){
        for(size_t j = i + 1; j < heightSize; j++){
            min = (height[i] <= height[j]) ? height[i] : height[j];
            tmp = min * (j - i);
            if(tmp > res){
                res = tmp;
            }
        }
    }

    return res;
}