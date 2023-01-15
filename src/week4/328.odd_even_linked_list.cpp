


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd_curr = odd_head;
        ListNode* even_curr = even_head;

        ListNode* curr = head->next->next;
        int i = 1;
        while (curr != nullptr) {
            if (i % 2 == 1) {
                // add to odd
                odd_curr->next = curr;
                odd_curr = odd_curr->next;
                curr = curr->next;
            } else {
                // add to even
                even_curr->next = curr;
                even_curr = even_curr->next;
                curr = curr->next;
            }
        }

        odd_curr->next = even_head;

        return odd_head;
    }
};
