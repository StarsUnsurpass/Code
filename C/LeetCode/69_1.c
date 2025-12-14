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
    if(x == 0 || x == 1) return x;

    int left = 0;
    int right = x;
    int res = 0;

    while(left <= right){
        int middle = (left + right) / 2;

        if(middle <= x / middle){
            res = middle;
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

    return res;
}