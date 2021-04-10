#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int M = 0;
    int row, col;
    
    int longestIncreasingPath(vector< vector<int> >& matrix) {
        vector<int> v;
        
        row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                recur(matrix, i, j, v);
            }
        }
        return M;
    }
    
    void recur(vector< vector<int> >& matrix, int i, int j, vector<int> v){
        if(!isInRange(i, j))
            return;
        
        M = M > v.size() ? M : v.size();
        
        if(isInRange(i+1, j) and matrix[i][j] < matrix[i+1][j]){
            v.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            recur(matrix, i+1, j, v);
            v.pop_back();
        }
        if(isInRange(i-1, j) and matrix[i][j] < matrix[i-1][j]){
            v.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            recur(matrix, i-1, j, v);
            v.pop_back();
        }
        if(isInRange(i, j+1) and matrix[i][j] < matrix[i][j+1]){
            v.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            recur(matrix, i, j+1, v);
            v.pop_back();
        }
        if(isInRange(i, j-1) and matrix[i][j] < matrix[i][j-1]){
            v.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            recur(matrix, i, j-1, v);
            v.pop_back();
        }
    }
    
    bool isInRange(int i, int j){
        return 0 <= i and i <= row and 0 <= j and j <= col;
    }
};

int main(void){
    Solution s;
    vector< vector<int> >matrix ( { 3,4,5 }, { 3,2,6 }, { 2,2,1 } );
    
    s.longestIncreasingPath(matrix);
    return 0;    
}