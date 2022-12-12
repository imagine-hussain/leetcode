# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Trivial case
        if root in [p, q, None]:
            return root

    def searchNodes(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> tuple('TreeNode', 'TreeNode'):
        if root == p:
            return [p, None]
        if root == q:
            return [None, q]


