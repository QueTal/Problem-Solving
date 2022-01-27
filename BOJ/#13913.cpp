#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, T;
bool visited[200001];
int parent[200001];

vector<int> path;

int main(void){
    cin >> N >> M;

    queue<int> q;
    q.push(N);
    
    while (!q.empty()){
        int pos = q.front();
        q.pop();
        
        if (pos == M) {
            int x = pos;
            while (x != N){
                path.push_back(x);
                x = parent[x];
            }
            path.push_back(x);
            cout << path.size()-1 << endl;
            break;
        }

        if (0 <= pos-1 and pos-1 <= 200000 and !visited[pos-1]) {
            parent[pos-1] = pos;
            visited[pos-1] = true;            
            q.push(pos-1);
        }
        if (0 <= pos+1 and pos+1 <= 200000 and !visited[pos+1]) {
            parent[pos+1] = pos;
            visited[pos+1] = true; 
            q.push(pos+1);
        }
        if (0 <= pos*2 and pos*2 <= 200000 and !visited[pos*2]) {
            parent[pos*2] = pos;
            visited[pos*2] = true;
            q.push(pos*2);
        }
    }
    for (int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
    return 0;
}