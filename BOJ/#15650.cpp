#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];

void dfs(int idx, vector<int>& v){
    if (v.size() == M) {
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
        return;
    }
    
    for (int i = idx; i <= N; i++){
        if (visited[i]) continue;
        v.push_back(i);
        visited[i] = true;
        dfs(i, v);
        v.pop_back();
        visited[i] = false;
    }
}
int main(void){
    cin >> N >> M;
    vector<int> v;
    dfs(1, v);
    return 0;
}