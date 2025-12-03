#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char* str = "babad";

    char res = char(str);
    printf("%s\n");

    return 0;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    char left = s[0];
    char right = s[len - 2];
    
}