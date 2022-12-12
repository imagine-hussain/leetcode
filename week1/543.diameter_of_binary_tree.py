# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return 0 if root is None else max(
            self.diameterOfBinaryTree(root.left),
            self.diameterOfBinaryTree(root.right),
            self.depth(root.left) + self.depth(root.right)
        )


    def depth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        return 0 if root is None else (
            max(self.depth(root.left), self.depth(root.right)) + 1
        )



