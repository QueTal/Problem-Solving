/**
 * 980. Unique Paths III
 * https://leetcode.com/problems/unique-paths-iii/
 */

class Solution {
public:
    int res = 0, empty = 1;
    vector<vector<int>> g;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r, c;
        g = grid;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {r = i; c = j;}
                else if (grid[i][j] == 0) ++empty;
            }
        }
        dfs(r, c, 0);
        return res;
    }
    
    void dfs(int r, int c, int cnt){
        if (r >= g.size() or c >= g[0].size() or r < 0 or c < 0 or g[r][c] == -1) return;
        
        if (g[r][c] == 2){
            if (cnt == empty) res++;
            return;    
        }
        
        g[r][c] = -1;
        
        dfs(r+1, c, cnt+1);
        dfs(r-1, c, cnt+1);
        dfs(r, c+1, cnt+1);
        dfs(r, c-1, cnt+1);
        
        g[r][c] = 0;
    }
};