#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(void){
    return 0;
}

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* dump = (struct ListNode*)malloc(sizeof(struct ListNode));
    dump->next = head;
    struct ListNode* fast = dump;
    struct ListNode* slow = dump;

    for(size_t i = 0; i < k - 1; i++){
        fast = fast->next;
    }
    struct ListNode* prev1 = fast;
    struct ListNode* node1 = prev1->next;
    fast = node1->next;

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* prev2 = slow;
    struct ListNode* node2 = slow->next;

    if(node1 != node2){
        prev1->next = node2;
        prev2->next = node1;

        struct ListNode* tmp = node2->next;
        node2->next = node1->next;
        node1->next = tmp;
    }

    struct ListNode* res;
    res = dump->next;
    free(dump);

    return res;
}