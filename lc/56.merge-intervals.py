"""
two intervals overlap
    [start1, end1], [start2, end2] when
    start2 <= end1 or if start1 <= end2

sort the interval array by the start indices of each interval

two pointer:
    left = 0, right start next to left
    if right and left overlap, keep a max "right side" boundary value, and the
    minimum boundary value, which should be left's start
     - if right's start value fits within the current [min, max], then update
        max_boundary with right's end value increment right
     - keep doing this until right doesn't fit in the interval, in which case
       refresh left, right and restart the process

Runtime: sorting step--> O(n log n)
         two pointer step --> O(n)
"""


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key=lambda x: x[0])
        print(sorted_intervals)
        ans = []
        left = 0
        right = 1
        left_int = sorted_intervals[left]
        curr_min = left_int[0]
        curr_max = left_int[1]
        while left < len(sorted_intervals) and right < len(sorted_intervals):
            right_int = sorted_intervals[right]
            if right_int[0] <= curr_max:
                curr_max = max(curr_max, right_int[1])
                right += 1
            else:
                ans.append([curr_min, curr_max])
                left = right
                right = left + 1
                left_int = sorted_intervals[left]
                curr_min = left_int[0]
                curr_max = left_int[1]
        ans.append([curr_min, curr_max])
        return ans
