/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> table = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        for (int i = 0; i < 13; i++) {
            while (num >= nums[i]) {
                res += table[i];
                num -= nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

