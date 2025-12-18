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
    int res = 0;

    int top = -1;
    bool* stack = (bool*)malloc(sizeof(bool) * len);
    int mark = 0;
    int temp = 0;

    for(int i = 0; i < len; i++){
        stack[i] = 0;

        if(s[i] == '('){
            top++;
            mark = i;
        }
        else{
            if(top >= 0){
                top--;
                stack[i] = 1;
                while(stack[mark] == 1){
                    mark--;
                }
                stack[mark] = 1;
            }
        }
    }

    for(int i = 0; i < len; i++){
        if(stack[i]){
            temp += 1;
        }
        else{
            temp = 0;
        }

        res = (temp > res) ? temp : res;
    }

    return res;
}