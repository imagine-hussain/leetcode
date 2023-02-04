// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <unordered_map>

using std::unordered_map;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> old_to_new;
        old_to_new.emplace(nullptr, nullptr);

        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            old_to_new.emplace(curr, new Node(curr->val));
        }

        Node* new_head = old_to_new.at(head);
        Node* new_curr = new_head;
        while (head != nullptr) {
            new_curr->next = old_to_new[head->next];
            new_curr->random = old_to_new[head->random];
            new_curr = new_curr->next;
            head = head->next;
        }

        return new_head;
    }
};
