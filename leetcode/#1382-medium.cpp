/**
 * 1382. Balance a Binary Search Tree
 * https://leetcode.com/problems/balance-a-binary-search-tree/
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
    vector<int> v;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return make(0, v.size()-1);    
    }
    
    void inorder(TreeNode *node){
        if (!node) return;
        inorder(node->left);
        v.push_back(node->val);
        inorder(node->right);
    }
    
    TreeNode* make(int start, int end){
        if (start > end) return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* cur = new TreeNode(v[mid]);

        cur->left = make(start, mid-1);
        cur->right = make(mid+1, end);
        return cur;
    }
};