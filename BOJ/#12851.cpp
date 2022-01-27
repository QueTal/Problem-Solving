#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M, T = 987654321;
bool visited[100001];
unordered_map<int, int> m;

int main(void){
    cin >> N >> M;

    queue< pair<int, int> > q;
    q.push(make_pair(N, 0));
    
    while (!q.empty()){
        int pos = q.front().first, t = q.front().second;
        q.pop();
        
        visited[pos] = true;
        
        if (pos == M) {
            m[t]++;
            T = min(T, t);
        }

        if (0 <= pos*2 and pos*2 <= 100001 and !visited[pos*2]) q.push(make_pair(pos*2, t+1));
        if (0 <= pos+1 and pos+1 <= 100001 and !visited[pos+1]) q.push(make_pair(pos+1, t+1));
        if (0 <= pos-1 and pos-1 <= 100001 and !visited[pos-1]) q.push(make_pair(pos-1, t+1));
    }

    cout << T << endl;
    cout << m[T];
    return 0;
}