/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* mid = find_mid(head);
        if (mid == nullptr)
            return head;
        // split at mid
        ListNode* rhs = mid->next;
        mid->next = nullptr;
        ListNode* lhs = sortList(head);
        rhs = sortList(rhs);

        return merge(lhs, rhs);
    }

    ListNode* merge(ListNode* lhs, ListNode* rhs) {
        if (lhs == nullptr || rhs == nullptr)
            return (lhs == nullptr) ? rhs : lhs;

        ListNode* res = nullptr;
        while (lhs != nullptr || rhs != nullptr) {
            ListNode* mini;
            if (lhs->val < rhs->val) {
                mini = lhs;
                lhs = lhs->next;
            } else {
                mini = rhs;
                rhs = rhs->next;
            }
            if (res == nullptr) {
                res = mini;
            } else {
                res->next = mini;
                res = res->next;
            }
        }

        if (lhs == nullptr) {
            res->next = rhs;
        } else {
            res->next = lhs;
        }

        return res;
    }

    ListNode* find_mid(ListNode* head) {
        for (ListNode* fast = head; fast != nullptr && fast->next != nullptr; head = head->next)
            fast = fast->next->next;
        return head;
    }

};
