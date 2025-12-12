#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int bulbSwitch(int n);

int main(){
    int n = 99999999;
    int res = bulbSwitch(n);
    printf("the number of bulu is %d\n", res);
    
    return 0;
}

int bulbSwitch(int n) {
    if(n == 0) return 0;

    bool* bulb = (bool*)malloc(n);
    int res = 0;
    int i = 1;

    for(int j = 0; j < n; j++){
        bulb[j] = 0;
    }

    while(i <= n){
        for(int j =  i - 1; j < n; j += i){
            if(bulb[j]){
                bulb[j] = 0;
            }
            else{
                bulb[j] = 1;
            }
        }

        i++;
    }

    for(int j = 0; j < n; j++){
        res += bulb[j];
    }

    return res;
}