/**
 * 994. Rotting Oranges
 * https://leetcode.com/problems/rotting-oranges/
 */

class Solution {
private: 
    int dir[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int t = -1, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        while (1){
            int cnt = 0;
            for (int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if (!visited[i][j] and grid[i][j] == 2) q.push({i, j});
                    else if (grid[i][j] == 1) cnt++;
                }
            }
            
            if (q.size() == 0 and cnt != 0) return -1;
            if (q.size() == 0 and cnt == 0) {
                if (t == -1) t = 0;
                break;
            }
        
            while(!q.empty()){
                int r = q.front().first, c = q.front().second;
                q.pop();
                
                visited[r][c] = true;
                
                for (int i = 0; i < 4; i++){
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if (nr < 0 or nc < 0 or nr >= n or nc >= m) continue;    
                    if (grid[nr][nc] == 1) grid[nr][nc] = 2;
                }
            }
            t++;
        }
        
        return t;
    }
};