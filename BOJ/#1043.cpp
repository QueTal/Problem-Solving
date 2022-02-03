#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, F;
bool fact[51];

int getParent(int parent[], int a){
    if (parent[a] == a) return a;
    return parent[a] = getParent(parent, parent[a]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> F;
    
    if (F == 0) { cout << M; return 0; }

    int parent[N+1];
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<int> truth;
    for (int i = 0; i < F; i++){
        int x;
        cin >> x;
        truth.push_back(x);
    }

    vector< vector<int> > party;
    for (int i = 0; i < M; i++){
        int x, num;
        vector<int> temp;
        
        cin >> x;
        for (int j = 0; j < x; j++){
            cin >> num;
            temp.push_back(num);
        }
        party.push_back(temp);

        for (int j = 1; j < temp.size(); j++) unionParent(parent, temp[j-1], temp[j]);
    }

    int cnt = 0;
    bool flag;
    for (int i = 0; i < party.size(); i++){
        flag = true;

        for (int j = 0; j < party[i].size(); j++){
            for (int k = 0; k < truth.size(); k++){
                if (findParent(parent, party[i][j], truth[k])){
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) cnt++;
    }

    cout << cnt;
    return 0;
}