#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

int main(void){
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode* current = dummy;

    int carry = 0;
    int result = 0;

    while(l1 != NULL || l2 != NULL || carry != 0){
        result = carry;

        if(l1 != NULL){
            result += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            result += l2->val;
            l2 = l2->next;
        }

        carry = result / 10;
        result = result % 10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = result;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    struct ListNode* res = dummy->next;
    free(dummy);

    return res;
}