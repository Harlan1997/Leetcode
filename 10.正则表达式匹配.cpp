/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        auto preMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            // ab .* || ab a*
            return isMatch(s, p.substr(2)) || preMatch && isMatch(s.substr(1), p);
        } else {
            return preMatch&& isMatch(s.substr(1), p.substr(1));
        }
    }
};
// @lc code=end

