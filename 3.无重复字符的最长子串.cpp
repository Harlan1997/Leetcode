/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int n = s.length();
        int k = -1;
        int res = 0;
        for(int i = 0; i < n; i++) {
            //abbab
            //hashmap[s[i]] > k确保k是往后移动
            if (hashmap.count(s[i]) && hashmap[s[i]] > k) {
                k = hashmap[s[i]];
            }
            hashmap[s[i]] = i;
            res = max(res, i - k);
        }
        return res;
    }
};
// @lc code=end

