/**
 * 36. Valid Sudoku
 * https://leetcode.com/problems/valid-sudoku/
 */ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[10];
        for(int i = 0; i < 10; i++) check[i] = 0;
        // row check
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if(check[board[i][j] - '0']) return false;
                    check[board[i][j] - '0'] = 1;
                }
            }
            for(int i = 0; i < 10; i++) check[i] = 0;
        }
        for(int i = 0; i < 10; i++) check[i] = 0;
        
        // col check
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    if(check[board[j][i] - '0']) return false;
                    check[board[j][i] - '0'] = 1;
                }
            }
            for(int i = 0; i < 10; i++) check[i] = 0;
        }
        for(int i = 0; i < 10; i++) check[i] = 0;
        
        // 3*3 check
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                for(int m = i; m < i + 3; m++){
                    for(int n = j; n < j + 3; n++){
                       if (board[m][n] != '.'){
                            if(check[board[m][n] - '0']) return false;
                            check[board[m][n] - '0'] = 1;
                        } 
                    }
                }
                for(int i = 0; i < 10; i++) check[i] = 0;
            }
            for(int i = 0; i < 10; i++) check[i] = 0;
        }
        return true;
    }
};