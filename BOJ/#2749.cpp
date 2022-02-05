#include <iostream>
#include <vector>

using namespace std;

long long N, cnt, mod = 1000000;
vector<int> v;

void solve(){
    cnt = 2;

    while (1){
        v.push_back((v[cnt]+v[cnt-1])%mod);
        cnt++;
        if (v[cnt] == 0 and v[cnt-1] == 1) break;
    }
}

int main(void){
    cin >> N;
    v.push_back(0); v.push_back(1); v.push_back(1);
    solve();
    cout << v[N%cnt];
    return 0;
}