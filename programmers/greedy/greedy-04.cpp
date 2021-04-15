/*
 * https://programmers.co.kr/learn/courses/30/lessons/42885
 * level : 2 / 구명보트
 */

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int lo = 0, hi = people.size()-1;
    
    sort(people.begin(), people.end());
    while(lo<=hi){
        if(people[lo]+people[hi] <= limit) {
            answer++; 
            lo++; hi--;
        }
        else {answer++; hi--;}
    }
    return answer;
}