/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (!m) {
            return 0;
        }
        for (int i = 0; i + m <= n; i++) {
            int flag = 1;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = -1;
                }
            }
            if (flag == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

