/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int state = 0;
        for (char c : s) {
            if (state == 0 && c == ' ') continue;
            else if (state == 0 && c == '+') state = 1;
            else if (state == 0 && c == '-') state = 2;
            else if (c >= '0' && c <= '9') {
                if (state == 0) state = 1;
                int x = c - '0';
                res = res * 10 + x;
                if (res > INT_MAX) {
                    break;
                }
            } else {
                break;
            }
        }
        if (state == 1 && res > INT_MAX) {
            return INT_MAX;
        } else if (state == 2) {
            res = - res;
            if (res < INT_MIN) {
                return INT_MIN;
            }
        }
        return res;
    }
};
// @lc code=end

