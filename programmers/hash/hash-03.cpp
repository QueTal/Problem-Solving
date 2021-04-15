/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42578
 * level : 2 / 위장
 * ******************************************************** */

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = clothes.size(), combo = 1;
    map<string, int> m;
    
    for(auto cloth : clothes){
        m[cloth[1]]++;
    }
    for(auto iter = m.begin(); iter!=m.end(); iter++){
        combo *= (iter->second+1);
    }
    
    return combo-1; 
}