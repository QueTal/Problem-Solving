/* 
 * https://programmers.co.kr/learn/courses/30/lessons/42842
 * level : 2 / 카펫
 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int d = sqrt((brown+4)*(brown+4)/4-4*(brown+yellow));
    int row = ((brown+4)/2+d)/2;
    int col = ((brown+4)/2-d)/2;
    
    return {row, col};
}