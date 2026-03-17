from typing import List

"""
Must use hashmap for [key that represents anagram] --> list of strings
what should we use for that key? can use sorted string?
can also use a frequency counter. Since 26 letters, can use arr[26] for frequency


"""


def get_alph_freq(s):
    freq = [0] * 26
    for c in s:
        freq[ord(c) - 97] += 1
    return tuple(freq)


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for s in strs:
            frequency = get_alph_freq(s)
            if frequency not in groups:
                groups[frequency] = [s]
            else:
                groups[frequency].append(s)

        return list(groups.values())
