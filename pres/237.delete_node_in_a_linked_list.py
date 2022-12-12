# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        list_len = self.getLength(node)

        # base - len 2
        if list_len == 2:
            ret = node.next
            node.next = None
            return ret
        order = self.get_order(node)

    def get_order(node):
        order = 0
        while node:
            if node.next is not None:
                if node.next > node:
                    order += 1
                else:
                    order -= 1
        return order
