class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        c = 0
        for s in stones:
            if s in jewels:
                c += 1
        return c
