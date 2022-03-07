/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<vector<vector<int>>, vector<string>> hset;
        for (string str :strs) {
            hset[calArray(str)].push_back(str);
        }
        for (auto elem : hset) {
            ret.push_back(elem.second);
        }
        return ret;
    }

    vector<vector<int>> calArray(string str) {
        vector<vector<int>> ret(100, vector<int>(1));
        for (char c : str) {
            ret[c - 'a'][0]++;
        }
        return ret;
    }
};
// @lc code=end

