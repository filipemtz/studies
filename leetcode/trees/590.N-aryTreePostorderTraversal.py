"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        else:
            lst = []
            for c in root.children:
                lst += self.postorder(c)
            lst += [root.val]
            return lst
