/* 
 * https://leetcode.com/problems/deepest-leaves-sum/
 * 1302. Deepest Leaves Sum
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
    int max_depth = 0;
    int res = 0;
    
    int deepestLeavesSum(TreeNode* root) {
        dfs_getDepth(root, 1);
        dfs_calculate(root, 1);
        return res;
    }
    
    void dfs_calculate(TreeNode* node, int level){
        if(node == nullptr) return;
        if(level == max_depth) res += node->val;
        dfs_calculate(node->left, level + 1);
        dfs_calculate(node->right, level + 1);
    }
    
    void dfs_getDepth(TreeNode* node, int level){
        if(node == nullptr) return;
        max_depth = max(max_depth, level);
        dfs_getDepth(node->left, level + 1);
        dfs_getDepth(node->right, level + 1);
    }
};