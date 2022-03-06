/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int reverse(int x) {
        int flag = x >= 0 ? 1 : -1;
        long n = 0;
        x = abs(x);
        while (x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n == (int)n ? flag * n : 0;
    }
};
// @lc code=end

