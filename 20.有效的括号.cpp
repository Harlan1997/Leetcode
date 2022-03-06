/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
//#include "leetcode.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else if (st.empty()) {
                return false;
            } else if (!st.empty() && c == st.top()) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

