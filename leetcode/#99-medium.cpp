/*
 * 99. Recover Binary Search Tree
 * https://leetcode.com/problems/recover-binary-search-tree/
 * https://leetcode.com/problems/recover-binary-search-tree/discuss/423225/C%2B%2B-Clear-Solution-(with-Explanation)
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
private: 
    void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
        if (root == nullptr) return;
        inorder(root->left, prev, first, second);
        
        if (prev){
            if (prev->val > root->val){
                if (!first) first = prev;
                second = root;
            }
        }
        prev = root;
        inorder(root->right, prev, first, second);
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        
        inorder(root, prev, first, second);
        swap(first->val, second->val);
        return;
    }
};