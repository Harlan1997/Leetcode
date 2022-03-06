/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 0x3f3f3f3f;
        int n = strs.size();
        if (n == 1) {
            return strs[0];
        }
        for (auto str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        string tmp;
        int res = 0;
        int flag = 1;
        for (int i = 0; i <= minLen; i++) {
            tmp = strs[0].substr(0, i);
            for (int j = 1; j < n; j++) {
                if (strcmp(strs[j].substr(0, i).c_str(), tmp.c_str())) {
                    flag = -1;
                    break;
                }
            }
            if (flag == 1) {
                res = i;
            } else {
                break;
            }
        }
        return strs[0].substr(0, res);
    }
};
// @lc code=end

