/**
 * 516. Longest Palindromic Subsequence
 * https://leetcode.com/problems/longest-palindromic-subsequence/
 * https://leetcode.com/problems/longest-palindromic-subsequence/discuss/1468396/C%2B%2BPython-2-solutions%3A-Top-down-DP-Bottom-up-DP-O(N)-Space-Clean-and-Concise
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), dp[1001][1001] = {0};
        
        for (int i = n-1; i >= 0; --i){
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j){
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};