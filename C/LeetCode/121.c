#include <stdio.h>
#include <stdlib.h>

int main(void){
    return 0;
}

int maxProfit(int* prices, int pricesSize) {
    if(pricesSize <= 1){
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < pricesSize; i++){
        if(minPrice >= prices[i]){
            minPrice = prices[i];
        }
        else{
            int tmp = prices[i] - minPrice;
            if(tmp > maxProfit){
                maxProfit = tmp;
            }
        }
    }

    return maxProfit;
}