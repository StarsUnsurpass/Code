#include <stdio.h>
#include <math.h>

int bulbSwitch(int n);

int main(){
    int n = 99999999;
    int res = bulbSwitch(n);
    printf("the number of bulu is %d\n", res);
    
    return 0;
}

int bulbSwitch(int n) {
    if (n <= 0) return 0;
    
    return (int)sqrt(n);
}