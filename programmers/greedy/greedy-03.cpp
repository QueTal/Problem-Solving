/*
 * https://programmers.co.kr/learn/courses/30/lessons/42883
 * level : / 큰수 만들기
 */ 

#include <string>

using namespace std;
 
string solution(string number, int k) {
    string answer = "";
    for (int j = 0, idx = -1; j < number.length() - k; j++) {
        char max = 0;
        for (int i = idx+1; i <= k + j; i++) {
            if (max < number[i]) {
                idx = i;
                max = number[i];
            }
        }
        answer += max;
    }
    return answer;
}