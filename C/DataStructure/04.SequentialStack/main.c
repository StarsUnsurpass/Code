#include "SequentialStack.h"
#include <stdlib.h>
#include <stdio.h>

/* 简单的 int 类型栈示例 */
int main(void) {
    /* 创建元素类型为 int 的顺序栈，容量为 5 */
    Stack* s = stack_create(5, sizeof(int));
    if (s == NULL) {
        fprintf(stderr, "无法创建栈。\n");
        return EXIT_FAILURE;
    }

    printf("栈已创建，容量 = %zu，当前大小 = %zu\n",
        stack_get_capacity(s), stack_get_size(s));

    /* 向栈中压入 1..5 */
    for (int i = 1; i <= 5; ++i) {
        if (!stack_push(s, &i)) {
            fprintf(stderr, "压入 %d 失败（栈可能已满）\n", i);
        }
        else {
            printf("已压入: %d （当前大小 = %zu）\n", i, stack_get_size(s));
        }
    }

    /* 尝试再压入一个元素以演示 is_full */
    int extra = 999;
    printf("尝试压入额外元素 %d：%s\n", extra,
        stack_push(s, &extra) ? "成功" : "失败（栈已满）");

    /* 查看栈顶元素（不弹出） */
    int top = 0;
    if (stack_peek(s, &top)) {
        printf("栈顶（peek）: %d\n", top);
    }
    else {
        printf("peek 失败（栈为空）\n");
    }

    /* 逐个弹出并打印直到栈为空 */
    while (!stack_is_empty(s)) {
        int val = 0;
        if (stack_pop(s, &val)) {
            printf("弹出: %d （剩余大小 = %zu）\n", val, stack_get_size(s));
        }
        else {
            printf("pop 失败\n");
            break;
        }
    }

    /* 清理 */
    stack_destroy(&s);
    if (s == NULL) {
        printf("栈已销毁。\n");
    }
    else {
        printf("警告：stack_destroy 未将指针置空。\n");
    }

    return EXIT_SUCCESS;
}