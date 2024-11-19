from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals: return [newInterval]
        output = []
        x, y = newInterval

        for i in range(len(intervals)):
            interval = intervals[i]
            if interval[0] > y:
                output.append(newInterval)
                output.extend(intervals[i:])
                return output
            elif interval[1] < x:
                output.append(interval)
                continue
            elif i + 1 < len(intervals) and intervals[i+1][0] > y:
                output.append([min(x, interval[0]), max(y, interval[1])])
                output.extend(intervals[i + 1:])
                return output
            elif y:
                x = min(x, interval[0])
                y = max(y, interval[1])
        
        if y:
            output.append([x, y])
        else:
            output.append(intervals[-1])
        return output



sol = Solution()
intervals = [[1,3],[6,9]]
newInterval = [2,5]
print(sol.insert(intervals, newInterval))
print("correct", [[1,5],[6,9]])
print()

intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]
print(sol.insert(intervals, newInterval))
print("correct", [[1,2],[3,10],[12,16]])
print()

intervals = [[1,5]]
newInterval = [2,3]
print(sol.insert(intervals, newInterval))
print("correct", [[1,5]])
print()

intervals = [[1,5]]
newInterval = [0,0]
print(sol.insert(intervals, newInterval))
print("correct", [[0,0],[1,5]])
print()

intervals = [[2,4],[5,7],[8,10],[11,13]]
newInterval = [3,6]
print(sol.insert(intervals, newInterval))
print("correct", [[2, 7], [5, 7], [8, 10], [11, 13]])
print()