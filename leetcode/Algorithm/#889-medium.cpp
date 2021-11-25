/**
 * 889. Construct Binary Tree from Preorder and Postorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    unordered_map<int, int> m;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int len = postorder.size();
        for (int i = 0; i < len; i++) m[postorder[i]] = i;
        return construct(preorder, postorder, 0, len-1, 0, len-1);
    }
    TreeNode* construct(vector<int>& pre, vector<int> post, int pre_start, int pre_end, int post_start, int post_end){
        TreeNode* cur = new TreeNode(pre[pre_start]);
        
        if (pre_start == pre_end) return cur;
        int new_end = m[pre[pre_start+1]];
        int len = new_end + 1 - post_start;
        
        cur->left = construct(pre, post, pre_start+1, pre_start + len, post_start, post_start+len-1);
        if (new_end+1 == post_end) return cur;
        cur->right = construct(pre, post, pre_start+len+1, pre_end, new_end+1, post_end-1);
        
        return cur;
    }
};
