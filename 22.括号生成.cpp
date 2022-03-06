/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<string> res;
    string tmp;
    vector<string> generateParenthesis(int n) {
        backTracking(n, n);
        return res;
    }

    void backTracking(int i, int j) {
        if (i == 0 && j == 0) {
            res.push_back(tmp);
            return;
        }
        if (i > 0) {
            tmp.push_back('(');
            backTracking(i - 1, j);
            tmp.pop_back();
        }
        if (i < j) {
            tmp.push_back(')');
            backTracking(i, j - 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

