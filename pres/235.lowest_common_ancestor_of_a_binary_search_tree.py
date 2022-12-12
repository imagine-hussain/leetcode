# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return (
            root if root in [p, q, None]
            else self.lowestCommonAncestor(child1, p, q)
                if (child1 := root.left if p.val < root.val else root.right) == (root.left if q.val < root.val else root.right)
            else root
        )
    
