from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for i in range(len(nums)):
            num_to_index[nums[i]] = i
        for i in range(len(nums)):
            target_num = target - nums[i]
            if target_num == nums[i]:
                if num_to_index[target_num] != i:
                    return [i, num_to_index[target_num]]
            elif target_num in num_to_index:
                return [i, num_to_index[target_num]]
        return []
