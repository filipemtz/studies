from collections import deque
from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        lst = []
        to_exp = deque()
        to_exp.append([root, 0])

        while len(to_exp) > 0:
            node, level = to_exp.popleft()
            if node is not None:
                while len(lst) < (level+1):
                    lst.append([])
                lst[level].append(node.val)
                for c in node.children:
                    to_exp.append([c, level + 1])

        return lst
