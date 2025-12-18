#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s);

int main(){
    char* s = "([}}])";

    bool res = isValid(s);
    
    if(res){
        printf("matched\n");
    }
    else{
        printf("dismatched\n");
    }

    return 0;
}

bool isValid(char* s) {
    int len = strlen(s);
    if(len % 2 == 1) return false;
    int capacity = len / 2;

    char* stack = (char*)malloc(sizeof(char) * capacity);
    int top = -1;

    for(int i = 0; i < len; i++){
        if((top + 1) < capacity && (s[i] == '(' || s[i] == '[' || s[i] == '{')){
            // 入栈操作：++top
            stack[++top] = s[i];
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(top == -1){
                free(stack);
                return false;
            }
            
            if ((s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{')) {
                free(stack);
                return false;
            }

            top--;
        }
        else{
            free(stack);
            return false;
        }
    }

    free(stack);
    return top == -1;
}