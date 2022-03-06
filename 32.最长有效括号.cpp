/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (!st.empty()) {
                    res = max(res, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end

