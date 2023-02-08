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
    int goodNodes(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int max_val) {
        if (root == nullptr) return 0;

        int is_good = (root->val >= max_val);
        max_val = is_good ? root->val : max_val;

        return dfs(root->left, max_val) + dfs(root->right, max_val) + is_good;
    }
};
