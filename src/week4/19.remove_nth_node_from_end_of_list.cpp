#include <stack>

/**
 * Definition for singly-linked list.
 */
// using std::stack;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (n--)
            fast = fast->next;

        ListNode* prev = nullptr;
        while (fast != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // head case
        if (slow == head)
            return head->next;

        // non-head removal
        prev->next = slow->next;
        return head;
    }
};

// stack solution -- 7ms
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        stack<ListNode *> s;
        ListNode* p = head;
        s.push(nullptr);
        while (p != nullptr) {
            s.push(p);
            p = p->next;
        }

        if (s.size() < n + 1)
            return nullptr;

        for (int i = 0; i < n - 1; i++) {
            s.pop();
        }
        // remove
        ListNode* res = s.top();
        s.pop();
        s.top()->next = res->next;

        if (res == head)
            head = head->next;

        delete res;

        return head;
    }
};
*/
