#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool visited[200001];

int main(void){
    cin >> N >> M;
    
    queue< pair<int, int> > q;
    q.push(make_pair(N, 0));
    
    while (!q.empty()){
        int pos = q.front().first, t = q.front().second;
        q.pop();
        visited[N] = true;

        if (pos == M) {
            cout << t;
            break;
        }
        if (0 <= pos*2 and pos*2 <= 200000 and !visited[pos*2]) {
            q.push(make_pair(pos*2, t));
            visited[pos*2] = true;
        }
        if (0 <= pos-1 and pos-1 <= 200000 and !visited[pos-1]) {
            q.push(make_pair(pos-1, t+1));
            visited[pos-1] = true;
        }
        if (0 <= pos+1 and pos+1 <= 200000 and !visited[pos+1]) {
            q.push(make_pair(pos+1, t+1));
            visited[pos+1] = true;
        }
        
    }
    return 0;
}