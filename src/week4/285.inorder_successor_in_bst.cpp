/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return nullptr;

        if (root == p)
            return root->right;
        if (root->left == p)
            return root;
        if (root->right == p)
            return root->right->right;

    }
};
