#include <vector>
#include <stack>

using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> s;
        do_path_sum(res, s, targetSum, root,  0);

        exit(1);
    }

private:
    void do_path_sum(vector<vector<int>>& res, vector<int>& s, int target, TreeNode* node, int cum_sum) {
        if (node == nullptr) {
            if (cum_sum == target) {
                res.push_back(vector<int>(s));
            }
            return;
        }

        int val = node->val;
        s.push_back(val);
        do_path_sum(res, s, target, node->left, cum_sum + node->val);
        do_path_sum(res, s, target, node->right, cum_sum + node->val);
        s.pop_back();

    }


};
