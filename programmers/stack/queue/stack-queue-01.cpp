/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42583
 * level : 2 / 다리를 지나는 트럭
 * ******************************************************* */

#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0;
    queue<int> q;
    
    for(int truck : truck_weights){
        while(1){
            if(q.empty()){
                q.push(truck);
                sum+=truck;
                answer++;
                break;
            }
            else if(q.size() == bridge_length){
                sum -= q.front();
                q.pop();
            }
            else{
                if(sum+truck > weight){
                    q.push(0);
                    answer++; 
                }
                else{
                    sum+=truck;
                    q.push(truck);
                    answer++;
                    break;
                }
            }
        }
    }
    return answer + bridge_length;
}