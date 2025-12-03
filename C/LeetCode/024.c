#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

int main(void){
    return 0;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dump = (struct ListNode*)malloc(sizeof( struct ListNode));
    dump->next = head;
    struct ListNode* current = dump;

    while(current->next != NULL && current->next->next != NULL){
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;

        first->next = second->next;
        second->next = first;
        current->next = second;

        current = first;
    }

    struct ListNode* res = dump->next;
    free(dump);
    return res;
}