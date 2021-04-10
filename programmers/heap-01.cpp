/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42626
 * level : 2 / 더 맵게
 * ******************************************************* */

#include <queue>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int sc:scoville) pq.push(sc);

    while(!pq.empty() ){
        int a = pq.top(); pq.pop();
        if(a >= K) return answer;
        else if(pq.size() == 0) return -1;
        int b = pq.top(); pq.pop();
        pq.push(a+b*2);
        answer++;
    }
    return -1;
}