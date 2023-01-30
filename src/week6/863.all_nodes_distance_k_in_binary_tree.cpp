#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // find node + keep stack traceback of predecessors
        stack<TreeNode*> parents;
        if (!find_target(root, target, parents))
            return vector<int>();

        vector<int> res;

        return res;
    }

    bool find_target(TreeNode* root, TreeNode* target, stack<TreeNode*>& parents) {
        if (root == nullptr) return false;
        parents.push(root);

        if (root == target
            || find_target(root->left,target, parents)
            || find_target(root->right,target, parents)
        ) return true;

        parents.pop();
        return false;
    }

};
