"""
Sliding window?
Divide and conquer?
prefix sum?

during one pass thru, count the num times that each sum occurs
for every sum encountered, u check freq map to see how many times the complment sum exists that
you need to sum up to k
add that to counter

can only subtract subarrays sum(0, j) - sum(0, i) when i < j

cur_prefix_sum - sum(0, i) = k
cur_prefix_sum - k = sum(0, i)

"""


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixes = [0]
        cur_sum = 0
        for i in range(len(nums)):
            cur_sum += nums[i]
            prefixes.append(cur_sum)

        counter = 0
        prefix_freq = {}
        for prefix in prefixes:
            target = prefix - k
            if target in prefix_freq:
                counter += prefix_freq[target]

            if prefix in prefix_freq:
                prefix_freq[prefix] += 1
            else:
                prefix_freq[prefix] = 1
        return counter
