/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
private:
    vector<int> in, post;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder; post = postorder;
        
        return dfs(0, in.size()-1, 0, post.size()-1);
    }
    
    TreeNode* dfs(int is, int ie, int ps, int pe){
        if(ps > pe){
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(post[pe]);
        int idx = 0;
        for (int i = is; i <= ie; i++) {
            if (post[pe] == in[i]) {
                idx = i;
                break;
            }
        }
        
        node->left = dfs(is, idx-1, ps, ps+idx-is-1);
        node->right = dfs(idx+1, ie, pe-ie+idx, pe-1);
        
        return node;
    }
};