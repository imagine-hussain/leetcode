/** Definition for singly-linked list. */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define MIN(a, b) ((a->val > b->val) ? a : b)

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode *head = malloc(sizeof(*head));
    while (1) {
    }
}

void add_min()
