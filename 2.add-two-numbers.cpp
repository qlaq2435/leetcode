/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a, b, c = 0, d;
        ListNode *h = NULL, *p = NULL;
        while (l1 || l2) {
            a = 0, b = 0;
            if (l1) a = l1->val;

            if (l2) b = l2->val;

            d = (a + b + c) % 10;

            if (!p) {
                p = new ListNode(d);
                h = p;
            } else {
                p->next = new ListNode(d);
                p = p->next;
            }

            if (l2) {
                l2 = l2->next;
            }
            if (l1) {
                l1 = l1->next;
            }
            c = (a + b + c) / 10;
        }
        if (c > 0) {
            p->next = new ListNode(c);
        }
        return h;
    }
};
// @lc code=end

