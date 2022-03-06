/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string longestPalindrome(string s) {
        //s[i+1:j-1]都是回文串, 那么如果s[i] == s[j], s[i:j]都是回文串
        int n = s.length();
        if (n < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        //dp[i][j]: i:j最长回文子串长度
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                int j = i + l - 1;
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (l < 3) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }   
                }
                if (dp[i][j] && l > maxLen) {
                    begin = i;
                    maxLen = l;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end

