from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 1: return intervals
        arr = []
        intervals = sorted(intervals, key=lambda x: x[0])

        left, right = intervals[0]
        for i in range(1, len(intervals)):
            if (intervals[i][0] - right) < 1:
                right = max(intervals[i][1], right)
                continue
            arr.append([left, right])
            left, right = intervals[i]
        arr.append([left, right])
        return arr

sol = Solution()

intervals = [[1,3],[2,6],[8,10],[15,18]]
print("correct", [[1,6],[8,10],[15,18]])
print(sol.merge(intervals))
print()

intervals = [[1,4],[4,5]]
print("correct", [[1,4],[4,5]])
print(sol.merge(intervals))