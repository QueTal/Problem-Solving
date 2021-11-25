/**
 * 203. Remove Linked List Elements
 * https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        
        if (!head) return head;
        
        while (temp){
            ListNode* n = temp;
            while (temp->next and temp->next->val == val){
                temp = temp->next;
            }
            n->next = temp->next;
            temp = n->next;
        }
        if (head->val == val) head = head->next;
        return head;
    }
};