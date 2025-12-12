#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canWinNim(int n);

int main(){
    int n = 234;
    bool res = canWinNim(n);
    if(res){
        printf("can win\n");
    }
    else{
        printf("cannot win\n");
    }

    return 0;
}

bool canWinNim(int n) {
    return n % 4 != 0;
}