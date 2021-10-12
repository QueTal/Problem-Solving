/**
 * 543. Diameter of Binary Tree
 * https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        solve(root, d);
        return d;
    }
    int solve(TreeNode* node, int& d){
        if (node == nullptr) return 0;
        
        int l = solve(node->left, d);
        int r = solve(node->right, d);
        
        d = max(d, l+r);
        return 1 + max(l, r);
    }
};