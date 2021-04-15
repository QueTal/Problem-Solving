/* 
 * https://programmers.co.kr/learn/courses/30/lessons/42884
 * level : 3 / 단속 카메라
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[1] < b[1]) return true;
    else  return false;
    
}

void eliminate(vector<vector<int>>& routes, int val){
    int i = 0;
    
    while (i < routes.size()){
        int in = routes[i][0], out = routes[i][1];
        if (in <= val and val <= out){
            routes.erase(routes.begin()+i);
            i = 0;
        }
        else i++;
    }
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    while (routes.size() != 0){
        int val =  routes[0][1];
        eliminate(routes, val);
        answer++;
    }
    return answer;   
}