#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {

        // K: old, V: new
        unordered_map<int, Node *> visited;

        return cloneDfs(node, visited);
    }

    Node* cloneDfs(Node* node, unordered_map<int, Node *>& visited) {
        auto found = visited.find(node->val);
        if (found != visited.end()) {
            return found->second;
        }

        Node *duplicate = new Node(node->val);
        visited[node->val] = duplicate;

        for (auto v : node->neighbors) {
            duplicate->neighbors.push_back(cloneDfs(node, visited));
        }

        return duplicate;
    }

};
