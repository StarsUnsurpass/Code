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
    long diff = (long)a - (long)b;
    long sign = diff >> 63;

    return (long)a + sign * ((long)a - (long)b);
}