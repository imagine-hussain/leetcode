#include <cstdint>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return doValidBst(root, INT64_MIN, INT64_MAX);
    }
private:
    bool doValidBst(TreeNode* root, int64_t min, int64_t max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return doValidBst(root->left, min, root->val) && doValidBst(root->right, root->val, max);
    }

};
