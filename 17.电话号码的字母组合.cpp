/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<string> table;
    vector<string> res;
    vector<char> tmp;
    vector<string> letterCombinations(string digits) { 
        if (digits == "") {
            return res;
        }
        table.push_back({});
        table.push_back({});
        table.push_back({'a', 'b', 'c'});
        table.push_back({'d', 'e', 'f'});
        table.push_back({'g', 'h', 'i'});
        table.push_back({'j', 'k', 'l'});
        table.push_back({'m', 'n', 'o'});
        table.push_back({'p', 'q', 'r', 's'});
        table.push_back({'t', 'u', 'v'});
        table.push_back({'w', 'x', 'y', 'z'});
        backTracking(digits, 0);
        return res;
    }

    void backTracking(string digits, int k) {
        if (tmp.size() == digits.size()) {
            string str;
            for (char c : tmp) {
                str += c;
            }
            res.push_back(str);
            return;
        }
        int num = digits[k] - '0';
        for (int i = 0; i < table[num].size(); i++) {
            tmp.push_back(table[num][i]);
            backTracking(digits, k + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

