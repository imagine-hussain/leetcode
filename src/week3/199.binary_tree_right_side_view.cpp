#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(height(root->right), height(root->left)) + 1;
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int h = height(root);
        // i := level
        // dp[i][0] := val
        // dp[i][1] := rightedness
        vector<vector<int>> dp(h);
        traverse(dp, root, 0, 1);

        return parse_dp(dp);
    }

    void traverse(vector<vector<int>>& dp, TreeNode* root, int level, int rightness) {
        if (root == nullptr) return;

        // Not been visited
        if (dp[level].size() == 0) {
            dp[level] = vector<int> {root->val, rightness};
        } else if (dp[level][1] < rightness) {
            dp[level][0] = root->val;
            dp[level][1] = rightness;
        }

        traverse(dp, root->left, level + 1, 2 * rightness);
        traverse(dp, root->right, level + 1, 2 * rightness + 1);

    }

    vector<int> parse_dp(vector<vector<int>>& dp) {
        vector<int> res(dp.size());
        for (int i = 0; i < dp.size(); i++)
            res[i] = dp[i][0];
        return res;
    }
};

