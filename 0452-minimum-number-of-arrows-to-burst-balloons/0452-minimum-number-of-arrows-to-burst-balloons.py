class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x: x[1], reverse=False)
        #雙指針
        slow, fast = 0, 1
        arrow = 0

        while True:
            if slow + fast >= len(points):
                arrow += 1
                break
            if points[slow][1] >= points[slow+fast][0]:
                fast += 1
            else:
                arrow += 1
                slow += fast
                fast = 1

        return arrow