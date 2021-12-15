/**
 * 147. Insertion Sort List
 * https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy, *cur = head;
        
        while (cur){            
            if (cur->next and cur->next->val < cur->val){
                while (prev->next and prev->next->val < cur->next->val)
                    prev = prev->next;
                
                ListNode* temp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;
                prev = dummy;
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};