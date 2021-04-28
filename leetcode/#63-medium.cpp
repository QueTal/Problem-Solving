/*
 * https://leetcode.com/problems/unique-paths-ii/
 * 63. Unique Paths II
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        if(grid[0][0] == 0) grid[0][0] = 1;
        else return 0;
        
        for(int i = 1; i < row; i++){
            grid[i][0] = grid[i-1][0] == 1 and grid[i][0] == 0 ? 1 : 0;
        }
        for(int i = 1; i < col; i++){
            grid[0][i] = grid[0][i-1] == 1 and grid[0][i] == 0 ? 1 : 0;
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(grid[i][j] == 0) grid[i][j] = grid[i-1][j] + grid[i][j-1];
                else grid[i][j] = 0;
            }
        }
        return grid[row-1][col-1];
    }
};