/* **********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42576 
 * level : 1 / 완주하지 못한 선수                                
 * ******************************************************** */

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(auto st:completion){
        m[st]++;
    }
    for(auto st: participant){
        if(!m.count(st) or m[st] == 0) {answer = st; break;}
        else {
            m[st]--;
        }
    }
    return answer;
}