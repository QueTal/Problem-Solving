/**
 * 130. Surrounded Regions
 * https://leetcode.com/problems/surrounded-regions/
 */

class Solution {
private:
    vector<vector<char>> b;
    int r, c;
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        
        if (row == 0) return; 
        int col = board[0].size();
        
        r = row; c = col;
        
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][col-1] == 'O') dfs(board, i, col-1);
        }
        for (int i = 0; i < col; i++){
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[row-1][i] == 'O') dfs(board, row-1, i);
        }
        
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& b, int row, int col){
        if ((row >= r or col >= c or row < 0 or col < 0) or b[row][col] != 'O') return;
        
        b[row][col] = 'C';
        dfs(b, row+1, col);
        dfs(b, row-1, col);
        dfs(b, row, col+1);
        dfs(b, row, col-1);
    }
};