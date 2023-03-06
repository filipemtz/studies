
from typing import List

"""
Note:

There is a O(nlog(n)) solution with O(n) memory:

Let l be a list as big as the size of the largest increasing sequence. The i-th position in l 
contains the smallest number that finishes an increasing sequence of size (i + 1). In other words, 
it is the last element of the increasing sequence that is the easiest to extend up to that size.
For example, if l is [1, 3, 5, 12, 15], there are sequences: 1-3, 1-X-5, 1-X-X-12, 1-X-X-X-15. The X
are numbers that we do not need to store.  Now, if the next element is 7, then, we should replace 
the 12 by 7, because:
(1) we have two size 4 increasing sequences: 1-X-X-12 and 1-X-5-7.
(2) any number that extend the second sequence also extend the first.
(3) the second is easier to extend.
Since l is sorted, we can binsearch the position to be replaced, when necessary. 

for n in nums:
    if n > l[-1], append n to l
    else, replace the smallest element that is larger to n by n. Use binsearch to find the position. 
"""


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        sz_max = 1
        meme = {}

        for i in range(len(nums)-1, -1, -1):
            seqs = []
            seqs.append([i])
            inserted = False
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    n = meme.get(j, 1) + 1
                    if (i not in meme) or (n > meme[i]):
                        meme[i] = n
                        inserted = True

            if inserted and (meme[i] > sz_max):
                sz_max = meme[i]

        return sz_max
