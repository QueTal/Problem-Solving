/**
 * 563. Binary Tree Tilt
 * https://leetcode.com/problems/binary-tree-tilt/
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
    int answer = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return answer;
    }
    
    int dfs(TreeNode* node){
        if (node == nullptr) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        answer += abs(left-right);
    
        return left+right+node->val;
    }
};

