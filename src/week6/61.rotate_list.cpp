
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int len = 0;

        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            len++;
        }

        prev->next = head;
        k = k % len;

        while (k--) {
            prev = prev->next;
        }
        prev->next = nullptr;

        return prev;
    }
};
