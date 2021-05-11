/* 
 * 109. Convert Sorted List to Binary Search Tree
 *  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}œ
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* toBST(ListNode* head, int lo, int hi){
        ListNode* temp = head;
        int mid = lo + (hi-lo) / 2, count = 0;
        
        if(lo > hi) return nullptr;
        
        while(count != mid){
            temp = temp->next;
            count++;
        }
        TreeNode* node = new TreeNode(temp->val);
        node->left = toBST(head, lo, mid - 1);
        node->right = toBST(head, mid+1, hi);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        
        while(temp){
            temp = temp->next;
            count++;
        }
        return toBST(head, 0, count-1);
    }
};