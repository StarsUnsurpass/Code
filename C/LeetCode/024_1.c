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
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;

    return newHead;
}