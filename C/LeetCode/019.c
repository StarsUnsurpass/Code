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
    if(head == NULL){
        return NULL;
    }

    struct ListNode* current = head;
    int cnt = 0;

    while(current != NULL){
        current = current->next;
        cnt++;
    }

    if(n == cnt){
        struct ListNode* newNode = head->next;
        free(head);
        return newNode;
    }

    current = head;
    for(size_t i = 0; i < cnt - n - 1; i++){
        current = current->next;
    }
    
    if(current != NULL && current->next != NULL){
        struct ListNode* tmp = current->next;
        current->next = tmp->next;
        free(tmp);
    }

    return head;
}