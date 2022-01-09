#include <iostream>
#include <vector>

using namespace std;

int N, M, A, B, dist = -1;
vector<int> connect[101];
bool visited[101];

void find(int from, int to, int cur){
    if (from == to) {
        dist = cur;
        return;
    }
    
    visited[from] = true;

    for (int i = 0; i < connect[from].size(); i++){
        int next = connect[from][i];
        if (visited[next]) continue;
        find(next, to, cur+1);
    }

}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> A >> B;
    cin >> M;
    
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }

    find(A, B, 0);
    cout << dist;
    return 0;
}