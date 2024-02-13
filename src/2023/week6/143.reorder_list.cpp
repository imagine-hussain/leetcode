struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        mergeList(head, reverseList(splitList(listMid(head))));
    }

    ListNode* listMid(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr)
                break;
            fast = fast->next;
            head = head->next;
        }
        return head;
    };

    ListNode* splitList(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        prev->next = nullptr;

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* tmp;
        while (l2 != nullptr) {
            tmp = l1->next;
            l1->next = l2;
            l1 = tmp;

            tmp = l2->next;
            l2->next = l1;
            l2 = tmp;
        }
    }

};
