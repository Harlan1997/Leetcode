/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (!l1 && !l2) {
            return NULL;
        }
        while (l1 || l2) {
            if (!l1) {
                tmp->next = l2;
                break;
            } else if (!l2) {
                tmp->next = l1;
                break;
            } else if (l1->val < l2->val) {
                ListNode* node = new ListNode(l1->val);
                tmp->next = node;
                tmp = tmp->next;
                l1 = l1->next;
            } else {
                ListNode* node = new ListNode(l2->val);
                tmp->next = node;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
// @lc code=end

