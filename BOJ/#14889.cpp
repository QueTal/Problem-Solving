#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int score[21][21]={0,};
int n = 0, answer = 100;

int getScore(vector<int>& v){
    int sum = 0;

    for (int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++) sum += score[v[i]][v[j]];
    }
    return sum;
}

void solve(vector<int>& cur, vector<bool>& visited){
    if (cur.size() == n / 2){
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) v.push_back(i);
        }
        int a = getScore(cur);
        int b = getScore(v);
        answer = min(answer, abs(a-b));
        return;
    }
    for(int i = 0; i < n; i++){
        if (visited[i]) break;
        cur.push_back(i);
        visited[i] = true;
        solve(cur, visited);
        cur.pop_back();
        visited[i] = false;
    }   
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> score[i][j]; 
        }
    }
    vector<int> a;
    vector<bool> visited(n, false);
    solve(a, visited);
    cout << answer;
    return 0;
}