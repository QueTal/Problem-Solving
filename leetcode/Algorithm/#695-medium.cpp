/**
 * 695. Max Area of Island
 * https://leetcode.com/problems/max-area-of-island/
 */

class Solution {
public:
    int M = 0;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]) M = max(M, dfs(grid, i, j));
            }
        }
        return M;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col){
        int sum = 0;
        
        grid[row][col] = 0;
        
        for (int i = 0; i < 4; i++){
            int r = row+dir[i][0], c = col+dir[i][1];
            if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size()) continue;
            if (grid[r][c]) sum += dfs(grid, r, c);
        }
        
        return sum+1;
    }
};