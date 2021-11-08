/**
 * 96. Unique Binary Search Trees
 * https://leetcode.com/problems/unique-binary-search-trees/
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+1, 0);
        
        if(n <= 1) return 1;
        memo[0] = memo[1] = 1; memo[2] = 2;
        for(int i = 3; i <= n; i++){
            for(int j = 0; j < i; j++){
                memo[i] += memo[j] * memo[i - j - 1];
            }
        }
        return memo[n];   
    }
};