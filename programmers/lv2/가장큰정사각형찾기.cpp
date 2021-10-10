/**
 * https://programmers.co.kr/learn/courses/30/lessons/12905
 */ 

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    if (board.size() == 1 and board[0].size() == 1){
        if (board[0][0] == 0) return 0;
        else return 1;
    }
    
    for (int i = 1; i < board.size(); i++){
        for (int j = 1; j < board[0].size(); j++){
            if (board[i][j] != 0) board[i][j] = min(board[i-1][j], min(board[i][j-1], board[i-1][j-1])) + 1;
            answer = max(answer, board[i][j]);
        }
    }
    return answer*answer;
}