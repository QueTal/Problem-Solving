
/* 
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * 329. Longest Increasing Path in a Matrix
 */

class Solution {
public:
    int dp[200][200];
    int row, col;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {        
        int res = 0;
        
        row = matrix.size(); col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j){
        int a, b, c, d;
        
        if(dp[i][j]) return dp[i][j];
        
        a = b = c = d = 0;
        int val = matrix[i][j];
        if(i < row - 1 and matrix[i+1][j] < val)   a = dfs(matrix, i+1, j);
        if(0 < i and matrix[i-1][j] < val)         b = dfs(matrix, i-1, j);
        if(j < col - 1 and matrix[i][j+1] < val)   c = dfs(matrix, i, j+1);
        if(0 < j and matrix[i][j-1] < val)         d = dfs(matrix, i, j-1);
        
        int M = max(a, max(b, max(c, d)));
        dp[i][j] = 1 + M;
        
        return dp[i][j];
    }
};