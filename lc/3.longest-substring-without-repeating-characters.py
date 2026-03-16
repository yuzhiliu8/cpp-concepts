"""
Keep a left pointer, the start of the current substring
keep incrementing a right pointer, adding the char at each index to a set of
seen chars
    if you reach the end, over
    if you hit a duplicate, subtract one from the length of the left and right
    substr
        move incr left pointer, removing chars from the set until no more
        duplicate
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        right = left
        seen = set()
        max_len = 0
        while left < len(s) and right < len(s):
            curr_char = s[right]
            if curr_char not in seen:
                seen.add(curr_char)
                right += 1
                curr_len = right - left
                if curr_len > max_len:
                    max_len = curr_len
            else:  # incr left until curr_char not in seen
                while curr_char in seen:
                    left_char = s[left]
                    seen.remove(left_char)
                    left += 1
                seen.add(curr_char)
                right += 1
            # print(f"left: {left} right: {right} max: {max_len}")
        return max_len
