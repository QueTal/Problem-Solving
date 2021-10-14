/**
 * 279. Perfect Squares
 * https://leetcode.com/problems/perfect-squares/
 */ 

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        int count = 1;
        
        dp[0]=0;
        
        while(count*count <= n) {
            int sq = count*count;
            for(int i = sq; i < n+1; i++) {
                dp[i] = min(dp[i-sq] + 1, dp[i]);
            }
            count++;
        }
        return dp[n];
    }
};