#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//stdbool.h不是bool.h
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main(void){
    char* str[] = {"flower", "folw", "flight"};
    // 计算数组元素个数
    int strsSize = sizeof(str) / sizeof(str[0]);

    char* result = longestCommonPrefix(str, strsSize);
    printf("%s\n", result);

    // 释放动态分配的内存
    free(result);

    return EXIT_SUCCESS;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0){
        return *strs;
    }

    if(strsSize == 1){
        return *strs;
    }

    int length = 0;
    bool inde = true;
    for(size_t i = 0; strs[0][i] != '\0' && inde; i++){
        char currentChar = strs[0][i];

        for(size_t j = 0; j < strsSize; j++){
            if(strs[j][i] == '\0' || currentChar != strs[j][i]){
                inde = false;
                break;
            }
        }

        if(inde) {  // 只有匹配时才增加长度
          length++;
      }
    }

    char* result = malloc(length + 1);
    strncpy(result, strs[0], length);
    result[length] = '\0';

    return result;
}