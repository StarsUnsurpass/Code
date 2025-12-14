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
    int middle = 0;

    while(left <= right){
        middle = left + (right - left) / 2;

        if(isBadVersion(middle)){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }

    if(isBadVersion(middle)){
        return middle;
    }
    else{
        return middle + 1;
    }
}

bool isBadVersion(int version){
    return true;
}