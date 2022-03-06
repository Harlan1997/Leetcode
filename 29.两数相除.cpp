/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend ^ divisor) >> 31 & 0x1 == 1) ? -1 : 1;
        long res = 0;
        long _dividend = abs((long) dividend);
        long _divisor = abs((long) divisor);
        while (_dividend >= _divisor) {
            long i = 1;
            long tmp = _divisor;
            while (_dividend >= tmp) {
                _dividend -= tmp;
                res += i;
                i = i << 1;
                tmp = tmp << 1;
            }
            cout << res << endl;
        }
        res *= sign;
        if (res > INT_MAX || res < INT_MIN) {
            return INT_MAX;
        }
        return (int)res;
    }
};
// @lc code=end

