# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# class Solution:
#     def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if head is None:
#             return None
#
#         l = []
#         while head is not None:
#             l.append(head)
#             head = head.next
#
#         head = l.pop()
#         curr = head
#         while l:
#             curr.next = l.pop()
#             curr = curr.next
#         curr.next = None
#
#         return head

from typing import Optional


class Solution:
    def reverseList(self, node: Optional[ListNode]) -> Optional[ListNode]:
        return (
            None if node is None or node.next is None
            else n2 if
            ((n2 := self.reverseList(node.next)) and not (node.next := None))
            else None
        )
        # second = self.reverseList(node.next)
        # node.next.next = node
        # node.next = None
        # return second

