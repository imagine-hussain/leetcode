/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    root->right = flipTree(root->right);
    return compareTrees(root->left, root->right);
  }

  TreeNode *flipTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = flipTree(right);
    root->right = flipTree(left);

    return root;
  }

  bool compareTrees(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr) return (p == nullptr && q == nullptr);
    return (q->val == p->val) && compareTrees(p->left, q->left) && compareTrees(p->right, q->right);
  }
};
