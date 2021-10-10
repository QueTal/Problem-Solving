/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42586
 * level : 2 / 기능개발
 * ******************************************************* */

#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int count = 1;
    
    for(int i = 0; i < progresses.size(); i++){
        int days = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i]) days++;
        q.push(days);
    }
    while(!q.empty()){
        int val = q.front(); q.pop();
        while(!q.empty() and val >= q.front()){
            count++; q.pop();
        }
        answer.push_back(count);
        count=1;
    }
    return answer;
}