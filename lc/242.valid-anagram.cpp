#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> w1;
        unordered_map<char, int> w2;

        for (int i = 0; i < s.length(); i++){
            w1[s[i]]++;
            w2[t[i]]++;
        }

        //Check equality of unordered_maps
        for (auto x : w1){
            if (!w2.contains(x.first)){
                return false;
            }
            if (w2[x.first] != x.second){
                return false;
            }
        }

        for (auto x : w2){
            if (!w1.contains(x.first)){
                return false;
            }
        }

        return true;
    }
};
// @lc code=en    std::set<int> mySet(myVector.begin(), myVector.end());d

