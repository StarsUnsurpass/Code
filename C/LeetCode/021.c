#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
int main(void){
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    else if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }

    struct ListNode* node1 = list1;
    struct ListNode* node2 = list2;
    struct ListNode* head;
    struct ListNode* current;

    if(node1->val < node2->val){
        head = node1;
        node1 = node1->next;
    }
    else{
        head = node2;
        node2 = node2->next;
    }
    current = head;

    while(node1 != NULL || node2 != NULL){
        struct ListNode* newNode;
        if(node1 == NULL){
            newNode = node2;
            node2 = node2->next;
        }
        else if(node2 == NULL){
            newNode = node1;
            node1 = node1->next;
        }
        else if(node1->val < node2->val){
            newNode = node1;
            node1 = node1->next;
        }
        else{
            newNode = node2;
            node2 = node2->next;
        }
        current->next = newNode;
        current = current->next;
    }

    return head;
}