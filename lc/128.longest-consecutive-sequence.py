from typing import List

"""
first create a set?
a number is at the bottom of a sequence if num-1 not in set

"""


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_len = 0
        for num in num_set:
            if num - 1 not in num_set:
                curr_len = 1
                next_num = num + 1
                while next_num in num_set:
                    curr_len += 1
                    next_num += 1
                max_len = max(max_len, curr_len)
        return max_len
