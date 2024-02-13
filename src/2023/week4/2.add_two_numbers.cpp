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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pow_10 = 1;
        int res = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int lhs = 0;
            int rhs = 0;
            if (l1 != nullptr) {
                lhs = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                rhs = l2->val;
                l2 = l2->next;
            }

            int sum = rhs + lhs;
            res += sum * pow_10;
            pow_10 *= 10;
        }

        if (res == 0)
            return new ListNode(0);

        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while (res) {
            int remainder = res % 10;
            res /= 10;

            // insert
            ListNode* new_node = new ListNode(remainder);
            if (head == nullptr) {
                head = new_node;
                curr = new_node;
            } else {
                curr->next = new_node;
                curr = curr->next;
            }
        }

        return head;
    }

};
