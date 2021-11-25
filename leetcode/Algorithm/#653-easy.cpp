/**
 * 653. Two Sum IV - Input is a BST
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = elements.size()-1;
        while(l < r){
            if (elements[l] + elements[r] == k) return true;
            else if (elements[l] + elements[r] > k) r--;
            else l++;
        }
        return false;
    }
    void inorder(TreeNode* node){
        if (!node) return;
        inorder(node->left);
        elements.emplace_back(node->val);
        inorder(node->right);
    }
private: 
    vector<int>elements;
};