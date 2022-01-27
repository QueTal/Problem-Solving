#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[10];
bool visited[10];
vector< vector<int> > answer;

void dfs(int idx, vector<int>& v){
    if (M == v.size()){
        answer.push_back(v);
        return;
    }
    for (int i = 0; i < N; i++){
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(i+1, v);
        visited[i] = false;
        v.pop_back();
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    vector<int> v;
    dfs(0, v);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (int i = 0; i < answer.size(); i++){
        for (int j = 0; j < M; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}