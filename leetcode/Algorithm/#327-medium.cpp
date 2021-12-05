/**
 * 337. House Robber III
 * https://leetcode.com/problems/house-robber-iii/
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
    int rob(TreeNode* root) {
        auto v = dfs(root);
        return max(v[0], v[1]);
    }
    
    vector<int> dfs(TreeNode* node){
        if (node == nullptr) return {0, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        vector<int> v(2, 0);
        
        v[0] = node->val + left[1] + right[1];
        v[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return v;
    }
};