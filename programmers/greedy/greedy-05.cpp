/* 
 * https://programmers.co.kr/learn/courses/30/lessons/42861
 * level : 3 / 섬 연결하기
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101] = {-1,};

bool comp(vector<int> a, vector<int> b){
    if(a[2] < b[2]) return true;
    else return false;
}

int find(int a){
    if (arr[a] < 0) return a;
    return arr[a] = find(arr[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    arr[b] = a;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    
    sort(costs.begin(), costs.end(), comp);

    for(int i = 0 ; i < n; i++ ) arr[i] = -1;
    
    for(auto cost : costs){
        int from = cost[0];
        int to = cost[1];
        int c = cost[2];
    
        if(merge(from, to)){
            answer += c;
            if(++cnt == n-1) break;
        }
    }
    return answer;
}