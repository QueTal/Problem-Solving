/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42627
 * level : 3 / 디스크 컨트롤러
 * ******************************************************* */

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;

struct my{
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }   
};
 
int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    priority_queue<vector<int>, vector<vector<int>>, my> pq; 
    
    sort(jobs.begin(), jobs.end());
    while (j < jobs.size() or !pq.empty()) {
        if (j < jobs.size() and time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            answer += time - pq.top()[0] + pq.top()[1];
            time += pq.top()[1];
            pq.pop();
        }
        else time = jobs[j][0];
    }
    return answer / jobs.size();
}