/**
 * 437. Path Sum III
 * https://leetcode.com/problems/path-sum-iii/
 * https://leetcode.com/problems/path-sum-iii/discuss/1525734/C%2B%2B-Python-Simple-and-Easy-DFS-Solutions-Faster-than-99
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
    int res = 0;
    unordered_map<int, int> m;
    
public:
    void dfs(TreeNode* node, int target, int sum){
        if (!node) return;
        
        sum += node->val;
        res += m[sum - target];
        
        m[sum]++;
        dfs(node->left, target, sum);
        dfs(node->right, target, sum);
        m[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        m[0]++;
        dfs(root, targetSum, 0);
        return res;
    }
};