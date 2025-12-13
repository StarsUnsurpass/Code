#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b);

int main(){
    int a = 100;
    int b = 200;

    int res = maximum(a, b);
    printf("the result is %d\n", res);

    return 0;
}

int maximum(int a, int b) {
    long k = ((long)a - (long)b) >> 63 & 1;

    return (1 - k) * a + k * b;
}