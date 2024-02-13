#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node (int val) { this->val = val; this->next = nullptr; this->prev = nullptr; }
    Node (int val, Node* next) { this->val = val; this->next = next; this->prev = nullptr; }
    Node (int val, Node* next, Node* prev) { this->val = val; this->next = next; this->prev = prev; }

};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // dp[i] := best using nums[0..i)
        vector<int> dp(nums.size(), -1);

        unordered_map<int, Node*> valmap;
        for (auto num : nums) {
            if (valmap.count(num) != 0)
                continue;

            Node* node = new Node(num);
            // next number
            auto next = valmap.find(num + 1);
            if (next != valmap.end()) {
                next->second->prev = node;
                node->next = next->second;
            }

            // prev number
            auto prev = valmap.find(num - 1);
            if (prev != valmap.end()) {
                prev->second->next = node;
                node->prev = prev->second;
            }
            valmap.emplace(num, node);
        }

        vector<Node* > heads;
        for (auto& pair : valmap) {
            Node* node = pair.second;
            if (node->prev == nullptr)
                heads.push_back(node);
        }

        int max_len = 0;
        for (auto& head : heads) {
            max_len = max(max_len, node_len(head));
        }

        return max_len;
    }

    int node_len(Node* head) {
        int len = 0;
        Node* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            len++;
        }
        return len;
    }

};
