/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
//#include "leetcode.h"
class Solution {
public:

    int binarySearch(vector<int> nums, int target, int left, int right) {
        int mid = (left + right) >> 1;
        if (target < nums[mid]) {
            return binarySearch(nums, target, left, mid - 1);
        } else if (target > nums[mid]) {
            return binarySearch(nums, target, mid + 1, right);
        } else {
            return 1;
        }
        return 0;
    }

    int search(vector<int>& nums, int target) {
        
    }
};
// @lc code=end

