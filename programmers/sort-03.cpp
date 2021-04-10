/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42747
 * level : 2 / H-index
 * ******************************************************* */

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int idx = 0, size = citations.size();
    
    sort(citations.begin(), citations.end(), greater<>());
    
    while(idx < size){
        if(idx >= citations[idx]) break;
        idx++;
    }
    return idx;
}