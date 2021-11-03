/**
 * 129. Sum Root to Leaf Numbers
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return res;
    }
    void dfs(TreeNode* node, string cur){
        if (!node) return;
        
        cur += to_string(node->val);
        if (!node->left and !node->right) { res += stoi(cur); return; }
        if (node->left) dfs(node->left, cur);
        if (node->right) dfs(node->right, cur);
        cur = cur.substr(0, cur.size()-1);
    }
};