#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
}

int main(void){
    return 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;
}