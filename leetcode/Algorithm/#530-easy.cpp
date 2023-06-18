/**
 * 530. Minimum Absolute Difference in BST
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 */

class Solution {
private:
    vector<int> v;
public:
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        int m = INT_MAX;
        for (int i = 0; i < v.size()-1; i++) {
            m = min(m, v[i+1] - v[i]);
        }
        return m;
    }
    void traverse(TreeNode* node) {
        if (node == nullptr) return;

        traverse(node->left);
        v.push_back(node->val);
        traverse(node->right);
    }
};