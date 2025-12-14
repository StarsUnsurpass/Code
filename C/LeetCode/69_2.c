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
    if(x == 0) return 0;

    long r = x;

    while(r * r > x){
        r = (r + x / r) / 2;
    }

    return (int)r;
}