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
    int capacity = strlen(s);
    if(capacity % 2 == 1){
        return false;
    }

    char* stack = (char*)malloc(sizeof(char) * capacity);
    int top = -1;

    int i = 0;

    while(i < capacity){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            top++;
            stack[top] = s[i];
        }
        else if(top >= 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
            if(s[i] == ')' && stack[top] == '(' || 
               s[i] == ']' && stack[top] == '[' || 
               s[i] == '}' && stack[top] == '{'){
                top--;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }

        i++;
    }

    free(stack);

    return top == -1;
}