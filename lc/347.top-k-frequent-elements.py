from typing import List

"""
Min frequency is 1 and max is n
create a frequency to value table/array

"""


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_to_value = [[] for _ in range(len(nums) + 1)]
        freq_map = {}
        for num in nums:
            freq_map[num] = freq_map.get(num, 0) + 1

        for num in freq_map:
            frequency = freq_map[num]
            freq_to_value[frequency].append(num)

        ans = []
        left = k
        for i in range(len(nums), -1, -1):
            if len(freq_to_value[i]) > 0:
                num_needed = min(len(freq_to_value[i]), left)
                ans.extend(freq_to_value[i][0:num_needed])
                left -= num_needed
                if left == 0:
                    return ans
        return ans
