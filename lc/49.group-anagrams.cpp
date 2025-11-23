#include <bits/stdc++.h>
/* 
vector of strs
group by anagram

should we use set of chars?
sort strs?
strs[i].length <= 100, so sorting is good enough here probably

loop through vector
    if sorted str not in map, then create new kv pair, and append str on the group

else if sorted is in the map, then just append

duplicates? i think you store multiple ont he same grouping
*/


/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (int i = 0; i < strs.size(); i++){
            std::string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());

            if (groups.contains(sorted)){
                groups[sorted].push_back(strs[i]);
            }
            else {
                groups[sorted] = std::vector<std::string>();
                groups[sorted].push_back(strs[i]);
            }
        }

        std::vector<std::vector<std::string>> res;
        for (const auto& kv : groups){
            res.push_back(kv.second);
        } 
        return res;
    }
};
// @lc code=end