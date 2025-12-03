#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

int main(void){
    return 0;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* dumy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumy->next = head;
    struct ListNode* current = dumy;
    int cnt = 0;

    while(current->next != NULL){
        current = current->next;
        cnt++;
    }
    struct ListNode* tail = current;

    if(cnt){
        k = k % cnt;
    }
    else{
        free(dumy);
        return head;
    }

    if(k == 0){
        free(dumy);
        return head;
    }

    current = dumy;

    for(size_t i = 0; i < cnt - k; i++){
        current = current->next;
    }
    struct ListNode* res = current->next;
    current->next = NULL;
    tail->next = head;

    free(dumy);
    return res;
}