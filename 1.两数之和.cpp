/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include "leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> complement;
        unordered_map<int, int> hmap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            complement.push_back(target - nums[i]);
            hmap[nums[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x = complement[i];
            if (hmap.count(x)) {
                if (i != hmap[x]) {
                    res.push_back(i);
                    res.push_back(hmap[x]);
                    break;
                }   
            }
        }
        return res;
    }
};
// @lc code=end

