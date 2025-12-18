#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int* stack = (int*)malloc(sizeof(int) * (len + 1));
    int top = -1;
    
    // 初始压入-1作为基准
    stack[++top] = -1;
    
    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            stack[++top] = i;
        }
        else{
            if(top > 0){
                top--;
                int cur_len = i - stack[top];
                max_len = (cur_len > max_len) ? cur_len : max_len;
            }
            else{
                stack[top] = i;
            }
        }
    }
    
    free(stack);
    return max_len;
}