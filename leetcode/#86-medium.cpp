
/* 
 * 86. Partition List
 * https://leetcode.com/problems/partition-list/
 */

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* tsmall, *tbig;
        
        tsmall = small; tbig = big;
        while(head){
            ListNode* node = new ListNode;
            if(head->val < x){
                node->val = head->val;
                tsmall->next = node;
                tsmall = tsmall->next;
            }
            else{
                node->val = head->val;
                tbig->next = node;
                tbig = tbig->next;
            }
            head = head->next;
        }
        tsmall->next = big->next;
        return small->next;
    }
};