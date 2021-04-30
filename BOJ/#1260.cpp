#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[1001];

void dfs(vector<int> arr[], int start){
    stack<int> st;

    st.push(start);
    while(!st.empty()){
        int cur = st.top(); st.pop();

        if(!visited[cur]) cout << cur << " ";
        visited[cur] = true;

        for(int i = 0; i < arr[cur].size(); i++){
            if(!visited[arr[cur][i]]) st.push(arr[cur][i]);
        }
    }
    cout << endl;
}

void bfs(vector<int> arr[], int start){
    queue<int> q;

    q.push(start);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if(!visited[cur])cout << cur << " ";
        visited[cur] = true;

        for(int i = 0; i < arr[cur].size(); i++){
            if(!visited[arr[cur][i]]) q.push(arr[cur][i]);
        }
    }
    cout << endl;
}

void initVisited(int n){
    for(int i = 0; i <= n; i++)
        visited[i] = false;
}

int main(void){
    int n, m, start;
    cin >> n >> m >> start;
    vector<int> arr[n+1];
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i = 0; i <= n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    for(int i = 0; i <= n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    dfs(arr, start);
    initVisited(n+1);

    for(int i = 0; i <= n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    bfs(arr, start);
    
    return 0;
}