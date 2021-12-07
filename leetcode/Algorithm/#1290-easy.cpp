/**
 * 1290. Convert Binary Number in a Linked List to Integer
 * https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        string s = "";
        int res = 0, exp = 0;
        
        while (head){
            s += to_string(head->val);
            head = head->next;
        }
        
        for (int i = s.size()-1; i >= 0; --i){
            res += pow(2, exp++) * (s[i] == '1' ? 1 : 0);
        }
        
        return res;
    }
};