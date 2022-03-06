/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "leetcode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryIn = 0;
        ListNode* ll = new ListNode(0);
        ListNode* curr = ll;
        while (l1 || l2 || carryIn) {
            int a = l1 != NULL ? l1->val : 0;
            int b = l2 != NULL ? l2->val : 0;
            int sum = a + b + carryIn;
            carryIn = sum / 10;
            ListNode* tmp = new ListNode(sum % 10);
            curr->next = tmp;
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return ll->next;
    }
};
// @lc code=end

