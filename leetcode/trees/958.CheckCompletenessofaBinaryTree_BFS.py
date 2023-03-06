class Solution:

    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        lst = []
        to_expand = deque()
        to_expand.append(root)

        self.bfs(to_expand=to_expand, expanded=lst)
        return not self.has_middle_nones(lst)

    def bfs(self, to_expand, expanded) -> List:
        while len(to_expand) > 0:
            node = to_expand.popleft()

            if node is None:
                expanded.append(None)
            else:
                expanded.append(node.val)
                to_expand.append(node.left)
                to_expand.append(node.right)

    def has_middle_nones(self, lst: List) -> bool:
        idx = len(lst) - 1

        while (idx >= 0) and (lst[idx] is None):
            idx -= 1

        while (idx >= 0):
            if lst[idx] is None:
                return True
            idx -= 1

        return False
