// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <vector>

using std::vector;

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> levels;
        fill_level_order(levels, root, 0);

        for (auto& level : levels)
            connect_level(level);

        return root;
    }

private:
    void fill_level_order(vector<vector<Node*>>& levels, Node* root, unsigned int height) {
        if (root == nullptr)
            return;
        fill_level_order(levels, root->left, height + 1);

        while (levels.size() <= height) {
            levels.push_back(vector<Node*>());
        }
        levels[height].push_back(root);

        fill_level_order(levels, root->right, height + 1);
    }

    void connect_level(vector<Node*>& level) {
        for (int i = 0; i < level.size() - 1; i++)
            level[i]->next = level[i + 1];
    }

};
