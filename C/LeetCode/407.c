#include <stdio.h>
#include <stdlib.h>

int main(void){
    int heightMap[][] = { { 1, 4, 3, 1, 3, 2 }, 
                          { 3, 2, 1, 3, 2, 4 }, 
                          { 2, 3, 3, 2, 3, 1 } };

    int heightMapSize = sizeof(heightMap) / sizeof(int);

    int heightMapCloSize = sizeof(heightMap[0]) / sizeof(int);

    return 0;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    int res = 0;
    int heightMapLineSize = heightMapSize / heightColSize;

    int left = 0;
    int right_x = heightColSize - 1;
    int left_x_max = 0;
    int right_x_max = 0;

    int right_y = heightMapLineSize - 1;
    int left_y_max = 0;
    int right_y_max = 0;

    int tmp_x = 0;
    int tmp_y = 0;

    for(size_t i = 0; i < heightMapLineSize; i++){
        while(left < right_x){
            if(heightMap[i][left] < heightMap[i][right_x]){
                if(heightMap[i][left] > left_x_max){
                    left_x_max = heightMap[i][left];
                    tmp_x = 0;
                }
                else{
                    tmp_x = left_x_max - heightMap[i][left];
                }
                left++;

                if(heightMap[i][left] > heightMap[right_y][left]){
                    tmp_y = 0;
                }
                else{
                    if(heightMap[i][left] > left_y_max){
                        left_y_max = heightMap[i][left];
                        tmp_y = 0;
                    }
                    else{
                        tmp_y = left_y_max - heightMap[i][left];
                    }
                }
            }
            else{
                if(heightMap[i][right] > right_x_max){
                    right_x_max = heightMap[i][right];
                    tmp_x = 0;
                }
                else{
                    tmp_x = right_x_max - heightMap[i][right];
                }
                right--;

                if(heightMap[i][left] < heightMap[right_y][left]){
                    tmp_y = 0;
                }
            }
        }
    }
}