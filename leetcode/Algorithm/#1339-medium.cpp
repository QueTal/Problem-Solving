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
        total = getSum(root);
        getSum(root);
        return answer %(int)(1e9+7);
    }
    long getSum(TreeNode* root){
        if (root==nullptr)  return 0;
        long sum = root->val + getSum(root->left) + getSum(root->right);
        answer = max(answer, sum*(total-sum));
        return sum;
    }
private: 
    long total = 0, answer = 0;
};