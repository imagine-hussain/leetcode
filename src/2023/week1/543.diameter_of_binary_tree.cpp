/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int self = depth(root->left) + depth(root->right);
        int max_left_right = std::max(left, right);
        return std::max(max_left_right, self);
    }

    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        return depth(root->left) + depth(root->right) + 1;
    }
};

