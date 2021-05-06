#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkBeam(vector<vector<int>>& board, int row, int col){
    // 양쪽 기둥
    if(row-1 >= 0){
        if(board[row-1][col] == 0 or board[row-1][col] == 2)
            return true;
        if(col+1 < board.size()){
           if(board[row-1][col+1] == 0 or board[row-1][col+1] == 2)
               return true;
        }
    }
    
    // 양쪽 보
    if(col+1 < board.size() and (board[row][col+1] == 1 or board[row][col+1] == 2)){
        if(col-1 >= 0 and (board[row][col-1] == 1 or board[row][col-1] == 2))
            return true;
    }
    return false;
}

bool checkPillar(vector<vector<int>>& board, int row, int col){
    // 바닥
    if(row == 0) return true; 
    
    // 기둥
    if(board[row][col-1] == 1 or board[row][col-1] == 2) return true;
    
    // 보
    if(row-1 >= 0){
        if(board[row-1][col] == 0 or board[row-1][col] == 2)
            return true;
    }
    
    if(board[row][col] == 1 or board[row][col] == 2) return true;
    
    return false;
}

bool isValid(vector<vector<int>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            int val = board[j][i];
            if(val == 0){
                if(!checkPillar(board, j, i)) return false;
            }
            else if(val == 1){
                if(!checkBeam(board, j, i)) return false;
            }
            else if(val == 2){
                if(!checkPillar(board, j, i)) return false;
                if(!checkBeam(board, j, i)) return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> board(n+1, vector<int>(n+1, -1));
    vector<vector<int>> answer;
    
    // 0 : 기둥 , 1 : 보 : 2 : 둘다
    for(auto build : build_frame){
        int x = build[0], y = build[1], type = build[2], mode = build[3];
        
        if(mode == 1){
            // 설치
            if(type == 0){
                // 기둥
                if(checkPillar(board, y, x)){
                    board[y][x] = (board[y][x] == -1) ? 0 : 2;
                }
            }
            else{
                // 보
                if(checkBeam(board, y, x)){
                    board[y][x] = (board[y][x] == -1) ? 1 : 2;
                }
            }
        }
        else {
            // 삭제
            int val = board[y][x];
            if(type == 0){
                // 기둥
                if(val == 0) board[y][x] = -1;
                else board[y][x] = 1;
            }
            else{
                if(val == 1) board[y][x] = -1;
                else board[y][x] = 0;
            }
            
            if(!isValid(board))
                board[y][x] = val;
        }
    }
    
    // board -> answer
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            int val = board[j][i];
            if(val == 0 or val == 1){
                answer.push_back({i,j,val});
            }
            else if (val == 2){
                answer.push_back({i,j,0});
                answer.push_back({i,j,1});
            }
        }
    }
    return answer;
}