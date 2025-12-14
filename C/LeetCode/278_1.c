#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int firstBadVersion(int n);
bool isBadVersion(int version);

int main(){
    return 0;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while(left < right){
        int middle = left + (right - left) / 2;

        if(isBadVersion(middle)){
            right = middle;
        }
        else{
            left = middle + 1;
        }
    }

    return left;
}

bool isBadVersion(int version){
    return true;
}