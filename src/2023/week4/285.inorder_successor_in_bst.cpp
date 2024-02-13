#include <queue>
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

        TreeNode* prev = nullptr;
        while (root != nullptr) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                prev = root;
                root = root->right;
            }
        }

        return prev;
    }
};
