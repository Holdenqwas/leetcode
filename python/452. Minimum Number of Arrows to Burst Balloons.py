from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 1: return 1

        points.sort(key=lambda x: x[0])

        count_shots = 1

        a, b = points[0]
        for arr in points:
            if arr[0] > b:
                count_shots += 1
                a, b = arr
                continue

            a = max(a, arr[0])
            b = min(b, arr[1])

        return count_shots


sol = Solution()
points = [[10,16],[2,8],[1,6],[7,12]]
print(sol.findMinArrowShots(points), 2)

points = [[1,2],[3,4],[5,6],[7,8]]
print(sol.findMinArrowShots(points), 4)

points = [[1,2],[2,3],[3,4],[4,5]]
print(sol.findMinArrowShots(points), 2)

points = [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
print(sol.findMinArrowShots(points), 2)
