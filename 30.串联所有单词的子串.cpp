/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> hashmap1;
        int strLen = s.length();
        int wordNum = words.size();
        int wordLen = words[0].length();
        for (auto word : words) {
            hashmap1[word]++;
        }
        for (int i = 0; i + wordNum * wordLen <= strLen; i++) {
            unordered_map<string, int> hashmap2;
            int cnt = 0;
            while (cnt < wordNum) {
                string str = s.substr(i + cnt * wordLen, wordLen);
                if (hashmap1.count(str)) {
                    hashmap2[str]++;
                    if (hashmap2[str] > hashmap1[str]) {
                        break;
                    }
                } else {
                    break;
                }
                cnt++;
            }
            if (cnt == wordNum) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

