/* 
 * 120. Triangle
 * https://leetcode.com/problems/triangle/
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        for(int i = 1; i < row; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j != 0 and j != triangle[i].size()-1) 
                    triangle[i][j] = min(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
                else if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];  
            }
        }
        return *min_element(triangle[row-1].begin(), triangle[row-1].end());   
    }
};