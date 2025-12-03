#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int main(void){
    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dump = (struct ListNode*)malloc(sizeof(struct ListNode));
    dump->next = head;

    struct ListNode* fast = dump;
    struct ListNode* slow = dump;

    for(size_t i = 0; i <= n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* tmp = slow->next;
    slow->next = tmp->next;
    free(tmp);

    struct ListNode* res = dump->next;
    free(dump);

    return res;
}