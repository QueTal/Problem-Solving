/**
 * 1008. Construct Binary Search Tree from Preorder Traversal
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* head = new TreeNode(), *temp = new TreeNode();
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        temp = head;
        solve(preorder, temp);    
        return head;
    }
    
    void solve(vector<int> preorder, TreeNode* c){
        vector<int> left, right;
        int cur = preorder[0];
        
        c->val = cur;
        for (int i = 1; i < preorder.size(); i++){
            if (preorder[i] < cur) left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
        }
        
        if (left.size() != 0) {
            auto t = new TreeNode();
            c->left = t;
            solve(left, c->left);
        }
        if (right.size() != 0) {
            auto t = new TreeNode();
            c->right = t;
            solve(right, c->right);
        }
    }
};