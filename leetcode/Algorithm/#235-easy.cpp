/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val) return p;
        else if (root->val == q->val) return q;
        
        if (root->val < p->val and root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else if (root->val > p->val and root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};