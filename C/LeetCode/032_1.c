#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int longestValidParentheses(char* s);

int main(){
    char* s = "(()())";

    int res = longestValidParentheses(s);

    printf("res is %d\n", res);
    
    return 0;
}

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int max_len = 0;

    int left = 0;
    int right = 0;

    for(int i = 0; i < len; i++){
        if(s[i] == '(') left++;
        else right++;

        if(left == right){
            max_len = (2 * left > max_len) ? 2 * left : max_len;
        }
        else if(right > left){
            left = right = 0;
        }
    }

    left = right = 0;

    for(int i = len - 1; i >= 0; i--){
        if(s[i] == '(') left++;
        else right++;

        if(left == right){
            max_len = (2 * left > max_len) ? 2 * left : max_len;
        }
        else if(left > right){
            left = right = 0;
        }
    }

    return max_len;
}