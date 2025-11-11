#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            if (m.contains(t)){
                return {(int) i , m[t]};
            }
            else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end

