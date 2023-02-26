#include <iostream>
#include <vector>

using namespace std;

int p[10001] = {0,};

int check(vector<int>& v, vector<int>& m){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < m.size(); j++){
            if (v[i] == m[j]) return v[i];
        }
    }
    return 0;
}

int solve(){
    int a, b, n;
    vector<int> l, m;
    int A, B;

    cin >> n;
    for (int i = 0; i <= n; i++) p[i] = 0;

    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        p[b] = a;
    }
    cin >> a >> b;
    A = a; B = b;
    
    while (p[a]){
        if (p[a] == b) return b;
        l.push_back(p[a]);
        a = p[a];
    }
    
    a = A;
    while (p[b]){
        if (p[b] == a) return a;
        m.push_back(p[b]);
        b = p[b];
    }

    return check(l, m);
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    
    cin >> t;

    while(t--){
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}
