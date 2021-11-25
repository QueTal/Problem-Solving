/*
 * 102. Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> answer;
        
        if(root == nullptr) return {};
        q.push({root, 0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            
            if(cur.second >= answer.size()){
                answer.push_back({});
            }
            answer[cur.second].push_back(cur.first->val);
            
            if(cur.first->left != nullptr) q.push({cur.first->left, cur.second+1});
            if(cur.first->right != nullptr) q.push({cur.first->right, cur.second+1});
        }
        
        return answer;
    }
};