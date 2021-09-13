#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
vector<int> v;

void solve(int sum, int cnt, vector<bool>& visited){
    if (cnt == 3){
        if (sum <= m) answer = max(answer, sum);
        return;
    }
    for(int i = 0; i < n; i++){
        if (visited[i]) continue;
        visited[i] = true;
        solve(sum + v[i], cnt + 1, visited);
        visited[i] = false;
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    
    cin >> n >> m;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    solve(0, 0, visited);
    cout << answer << endl;
    return 0;
}