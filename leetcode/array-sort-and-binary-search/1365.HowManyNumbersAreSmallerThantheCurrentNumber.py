
import bisect


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        s = sorted(nums)
        return [bisect.bisect_left(s, n) for n in nums]
