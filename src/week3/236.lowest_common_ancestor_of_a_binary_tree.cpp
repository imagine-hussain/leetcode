#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> q_stack;
        stack<TreeNode *> p_stack;
        search_stack(root, q, q_stack);
        search_stack(root, p, p_stack);

        return compare_stack(p_stack, q_stack);
    }

    TreeNode* compare_stack(stack<TreeNode *> lhs, stack<TreeNode *> rhs) {
        TreeNode *top = nullptr;

        while (1) {
            if (lhs.empty() || rhs.empty()) break;
            TreeNode *l = lhs.top();
            TreeNode *r = rhs.top();
            if (l != r) break;
            top = l;
            lhs.pop();
            rhs.pop();
        }

        return top;
    }

    bool search_stack(TreeNode* root, TreeNode *target, stack<TreeNode *>& q) {
        if (root == target) {
            q.push(root);
            return true;
        }
        if (root == nullptr) return false;

        if (search_stack(root->left, target, q) || search_stack(root->right, target, q)) {
            q.push(root);
            return true;
        }

        return false;

    }


};
