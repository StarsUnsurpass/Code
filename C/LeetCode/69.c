#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x);

int main(){
    int x = 2147483647;
    int res = mySqrt(x);
    printf("the sqrt of mySqrt is %d\n", res);
    return 0;
}

int mySqrt(int x) {
    long x_temp = x;
    int left = 0;
    int right = x;
    long middle = 0;

    while(left <= right){
        middle = (left + right) / 2;
        if(middle * middle <= x_temp){
            left = middle + 1;
        }
        else if(middle * middle > x_temp){
            right = middle - 1;
        }
    }

    if(middle * middle > x){
        return middle - 1;
    }
    else{
        return middle;
    }
}