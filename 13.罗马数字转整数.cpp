/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap;
        hashmap['M'] = 1000;
        hashmap['D'] = 500;
        hashmap['C'] = 100;
        hashmap['L'] = 50;
        hashmap['X'] = 10;
        hashmap['V'] = 5;
        hashmap['I'] = 1;
        int n = s.size();
        int pre = hashmap[s[0]];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (hashmap[s[i]] > pre) {
                res -= pre;
            } else {
                res += pre;
            }
            pre = hashmap[s[i]];
        }
        res += pre;
        return res;
    }
};
// @lc code=end

