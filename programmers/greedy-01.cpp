/*
 * https://programmers.co.kr/learn/courses/30/lessons/42862
 * level : 1 / 체육복
 */

#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++)
            if(lost[i] == reserve[j]) {lost[i] = -1; reserve[j] = -2; answer++;}
    }
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j] or lost[i] == reserve[j] + 1 or lost[i] == reserve[j] - 1){
                answer++; 
                reserve[j] = -2;
                break;
            }
        }
    }
    return answer;
}