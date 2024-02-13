#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // dp[i] := (min_rightness, max_rightness) at the i-th level
        vector<tuple<int, int>> dp(height(root), tuple<int, int>(INT_MAX, INT_MIN));

        traverse(root, dp, 0, 1);

        cout << "\n\n" << endl;

        int max_diff = 0;
        for (int i = 0; i < dp.size(); i++) {
            int l = get<0>(dp[i]);
            int r = get<1>(dp[i]);
            int diff = r - l;
            cout << "i: " << i << ",\t";
            cout << "l: " << l << ",\tr: " << r << ";\t";
            cout << "diff: " << diff << endl;
            max_diff = max(max_diff, diff);
        }

        return max_diff;
    }

    void traverse(TreeNode* root, vector<tuple<int, int >>& dp, int level, int rightness) {
        if (root == nullptr) return;

        cout << "node: " << root->val << ",\t level: " << level << ",\t rightness" << rightness << endl;

        int l = min(get<0>(dp[level]), rightness);
        int r = max(get<1>(dp[level]), rightness);
        dp[level] = tuple<int, int>(l, r);

        traverse(root->left, dp, level + 1, 2 * rightness);
        traverse(root->right, dp, level + 1, 2 * rightness + 1);
    }

    int height(TreeNode* root) {
        return (root != nullptr)
            ? max(height(root->left), height(root->right)) + 1
            : 0;
    }
};
