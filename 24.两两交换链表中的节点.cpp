/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

    pair<ListNode*, ListNode*> rev(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (tail != prev) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;        
        }
        return {tail, head};
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* hair = new ListNode();
        hair->next = head;
        ListNode* pre = hair;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < 2; i++) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            pair<ListNode*, ListNode*> res = rev(head, tail);
            pre->next = res.first;
            pre = res.second;
            head = pre->next;
        }
        return hair->next;
    }
};
// @lc code=end

