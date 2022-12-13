#include <vector>
#include <iostream>

#define MID(x, y) ((x + y) / 2)

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;

        return doSortedarrayToBsT(nums, 0, nums.size() - 1);
    }

    // hi is non-inclusive
    TreeNode* doSortedarrayToBsT(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) return nullptr;

        int mid = MID(lo, hi);

        if (mid == hi || mid == lo)
            return new TreeNode(nums[mid]);

        TreeNode *root = new TreeNode(TreeNode(nums[mid]));
        std::cout << "root" << nums[mid] << std::endl;

        root->left = doSortedarrayToBsT(nums, lo, mid);
        root->right = doSortedarrayToBsT(nums, mid + 1, hi);

        return root;
    }

};
