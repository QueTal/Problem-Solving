/* 
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast, *slow;
        fast = slow = head;
        
        n += 1;
        while(n--){
            if(fast) fast = fast->next;
            else break;
        }
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        if (n == -1 or slow != head) slow->next = slow->next->next;
        else head = head->next;
        
        return head;
    }
};