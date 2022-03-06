/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        for (ListNode* list : lists) {
            if (list) {
                q.push(list);
            }
        }
        while (!q.empty()) {
            ListNode* t = q.top();
            q.pop();
            tail->next = t;
            tail = t;
            if (t->next) {
                q.push(t->next);
            }
        }
        return head->next;
    }
};
// @lc code=end

