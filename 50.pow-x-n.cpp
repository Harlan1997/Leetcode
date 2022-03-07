/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//#include "leetcode.h"
class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        return n >= 0 ? quickMult(x, pow) : 1.0 / quickMult(x, pow);
    }

    double quickMult(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double y = quickMult(x, n / 2);
        return n % 2 ? y * y * x : y * y;
    }
};
// @lc code=end

