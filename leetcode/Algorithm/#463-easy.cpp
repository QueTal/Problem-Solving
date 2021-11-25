/**
 * 463. Island Perimeter
 * https://leetcode.com/problems/island-perimeter/
 */

class Solution {
private:
    int visited[101][101];
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:    
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int answer = 0;
        bool find = false;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            
            int cnt = 0;
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if (nr >= grid.size() or nc >= grid[0].size() or nr < 0 or nc < 0) continue;
                if (grid[nr][nc] == 1) {
                    cnt++;
                    if (!visited[nr][nc]){
                        q.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
            answer += (4-cnt);
        }
        return answer;
    }
};