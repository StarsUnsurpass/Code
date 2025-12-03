#include <stdio.h>
#include <stdib.h>

struct ListNode{
    int val;
    struct ListNode* next;
}

int main(void){
    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dummy;
    dummy->next = head;
    struct ListNode* slow = dummy;
    int sign = 0;

    while(slow->next != NULL){
        struct ListNode* fast = slow;
        while(fast->next != NULL){
            fast = fast->next;
            struct ListNode* tmp = fast->next;
            if(slow->next->val == fast->val){
                fast->next = tmp->next;
            }
        }
    }
}