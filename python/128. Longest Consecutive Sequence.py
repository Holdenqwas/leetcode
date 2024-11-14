# https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) < 2: return len(nums)
        store = dict()
        max_count = 0

        for val in nums:
            l, r = val, val
            if val in store: continue
            if (val - 1) in store:
                ll, rl = store[val-1]
                l = ll
            if (val + 1) in store:
                lr, rr = store[val+1]
                r = rr

            if l != val and r != val:
                store[l][1] = r
                store[r][0] = l
            elif l != val:
                store[l][1] = val
            elif r != val:
                store[r][0] = val
            
            store[val] = [l, r]
            max_count = max(max_count, r - l)
        return max_count + 1
        
sol = Solution()

nums = [100,4,200,3,1,2]
print(sol.longestConsecutive(nums))
nums = [0,3,7,2,5,8,4,6,1]
print(sol.longestConsecutive(nums))
nums = []
print(sol.longestConsecutive(nums))
nums = [1]
print(sol.longestConsecutive(nums))