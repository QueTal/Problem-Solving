/**
 * 988. Smallest String Starting From Leaf
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
    string res;
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return res;
    }
    
    void dfs(TreeNode* node, string cur){
        if (!node) return;
        
        char temp = 'a' + node->val;
        cur = temp + cur;
        if (!node->left and !node->right) {
            if (res == "") res = cur;
            else res = min(res, cur);
            return;
        }
        if (node->left) dfs(node->left, cur);
        if (node->right) dfs(node->right, cur);
        cur = cur.substr(1);
    }
};