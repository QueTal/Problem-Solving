/**
 * 1339. Maximum Product of Splitted Binary Tree 
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    int maxProduct(TreeNode* root) {
        long sum = getSum(root);
        long answer = 0;
        for(auto h : history){
            long target = ((sum - h) * h) % (int)(1e9+7);
            answer = answer > target ? answer : target;
        }
        return answer;
    }
    long getSum(TreeNode* root){
        if (root == nullptr) return root->val;
        if (root->left) root->val += getSum(root->left);
        if (root->right) root->val += getSum(root->right);
        history.emplace_back(root->val);
        return root->val;
    }
private: 
    vector<long> history;
};