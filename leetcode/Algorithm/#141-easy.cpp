/**
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow, *fast;
        
        if(head==nullptr or head->next==nullptr) return false;
        
        slow = head; fast = head->next;
        while(fast!=nullptr and fast->next!=nullptr){
            if(slow==fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};