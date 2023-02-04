struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* last = head;
        while (last != nullptr && last->next != nullptr) {
            ListNode* curr = last->next;

            // disconnect curr
            // # safety: last != null && (last->next := curr) != null
            last->next = curr->next;
            // Find place to put curr
            if (curr->val > last->val) {
                // put curr back where it was; now curr is last
                curr->next = last->next;
                last->next = curr;
                last = curr;
            } else if (curr->val <= head->val) {
                // make this the head of the list
                curr->next = head;
                head = curr;
            } else {
                // have to insert in the middle somewhere
                ListNode* prev = head;
                // # safety: curr does not belong at end: will not deref null
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }
                curr->next = prev->next;
                prev->next = curr;
            }
        }


        return head;
    }
};

