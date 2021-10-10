/*
 * https://programmers.co.kr/learn/courses/30/lessons/43105
 * level : 3 / 정수 삼각형
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int row = triangle.size();
    auto copy = triangle;
    
    for(int i = 0; i < row-1; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            copy[i+1][j] = max(copy[i+1][j], copy[i][j] + triangle[i+1][j]);
            copy[i+1][j+1] = max(copy[i+1][j+1], copy[i][j] + triangle[i+1][j+1]);
        }
    }
    return *max_element(copy[row-1].begin(), copy[row-1].end());
}