/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1) {
            return s;
        }
        vector<string> table(min(numRows, n));
        int row = 0;
        int step = -1;
        for (int i = 0; i < n; i++) {
            table[row] += s[i];
            if (row == 0 || row == numRows - 1) step = -step;
            row += step;
        }
        string res;
        for (string row : table) {
            res += row;
        }
        return res;
    }
};
// @lc code=end

