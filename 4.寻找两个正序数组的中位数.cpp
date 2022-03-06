/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include "leetcode.h"
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m + n;
        //even sum / 2 - 1, sum / 2
        //odd  sum / 2
        if (!m) {
            return n % 2 == 0 ? (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0 : nums2[n / 2] * 1.0;
        } else if (!n) {
            return m % 2 == 0 ? (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0 : nums1[m / 2] * 1.0;
        }
        int mid = sum >> 1;
        int res;
        int cnt = 0;
        int idx1 = 0;
        int idx2 = 0;
        while (cnt < mid) {
            if (idx1 >= m) {
                res = nums2[idx2];
                idx2++;
            } else if (idx2 >= n) {
                res = nums1[idx1];
                idx1++;
            } else if (nums1[idx1] < nums2[idx2]) {
                res = nums1[idx1];
                idx1++;
            } else {
                res = nums2[idx2];
                idx2++;
            }
            cnt++;
        }
        if (sum % 2 == 0) {
            if (idx1 >= m) {
                res += nums2[idx2];
            } else if (idx2 >= n) {
                res += nums1[idx1];
            } else if (nums1[idx1] < nums2[idx2]) {
                res += nums1[idx1];
            } else {
                res += nums2[idx2];
            }
        } else {
            if (idx1 >= m) {
                res = nums2[idx2] * 2;
            } else if (idx2 >= n) {
                res = nums1[idx1] * 2;
            } else if (nums1[idx1] < nums2[idx2]) {
                res = nums1[idx1] * 2;
            } else {
                res = nums2[idx2] * 2;
            }
        }
        return res / 2.0;
    }
};
// @lc code=end

