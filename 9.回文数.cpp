/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x / 10 == 0) {
            return true;
        }
        long rev = 0;
        int tmp = x;
        while (tmp) {
            rev = rev * 10 + tmp % 10;
            tmp /= 10;
        }
        return rev == x;
    }
};
// @lc code=end

