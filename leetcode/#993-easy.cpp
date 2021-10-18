/**
 * 993. Cousins in Binary Tree
 * https://leetcode.com/problems/cousins-in-binary-tree/
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
    TreeNode* px, *py;
    int dx, dy;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        find(root, nullptr, x, y, 0);
        if (px == py or dx != dy) return false;
        return true;
    }
    
    void find(TreeNode* node, TreeNode* parent, int x, int y, int depth){
        if (node == nullptr) return;
        
        if (node->val == x){
            px = parent; dx = depth;
        }
        else if (node->val == y){
            py = parent; dy = depth;
        }
        
        find(node->left, node, x, y, depth+1);
        find(node->right, node, x, y, depth+1);
    }
};