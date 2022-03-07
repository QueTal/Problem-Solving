/**
 * 21. Merge Two Sorted Lists
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* head = newHead;
        
        while(l1 and l2){
            if(l1->val < l2->val){
                newHead->next = new ListNode(l1->val);
                l1 = l1->next;                
            }
            else{
                newHead->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            newHead = newHead->next;
        }
        // if l1 is left
        if(l1){
            newHead->next = l1;
        }
        // if l2 is left
        else if(l2){
            newHead->next = l2;
        }
        return head->next;
    }
};