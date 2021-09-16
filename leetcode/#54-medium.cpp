/**
 * 54. Spiral Matrix
 * https://leetcode.com/problems/spiral-matrix/
 */ 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = 0, c = 0, R = matrix.size()-1, C = matrix[0].size()-1;
        vector<int> answer;
        
        if(matrix.size() == 0) return {};
        
        while (r <= R and c <= C){
            for(int i = c; i <= C; i++) answer.push_back(matrix[r][i]);
            for(int i = r+1; i <= R; i++) answer.push_back(matrix[i][C]);
            
            if (r != R and c != C){
                for(int i = C-1; i >= c; i--) answer.push_back(matrix[R][i]);
                for(int i = R-1; i > r; i--) answer.push_back(matrix[i][c]);
            }
            r++; c++; R--; C--;
        }
        return answer;
    }
};