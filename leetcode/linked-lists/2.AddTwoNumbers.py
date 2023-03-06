
from typing import Optional,

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        digits = []
        carry = 0

        while (l1 is not None) or (l2 is not None):
            v1 = v2 = 0
            if l1 is not None:
                v1 = l1.val
                l1 = l1.next
            if l2 is not None:
                v2 = l2.val
                l2 = l2.next

            sum = v1 + v2 + carry
            digit = sum % 10
            carry = sum // 10

            digits.append(digit)

        if carry > 0:
            digits.append(carry)

        root = None
        for idx in range(len(digits)-1, -1, -1):
            root = ListNode(digits[idx], root)

        return root
