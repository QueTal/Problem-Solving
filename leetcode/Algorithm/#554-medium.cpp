/*
 * 554. Brick Wall
 * https://leetcode.com/problems/brick-wall/
 */

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> um;
        int h = wall.size(), res = h;
        
        for (int i = 0; i < h; i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size()-1; j++) {
                sum += wall[i][j];
                um[sum]++;                
                res = min(res, h-um[sum]);
            }
        }
        return res;
    }
};