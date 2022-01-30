#include <iostream>

using namespace std;

#define mod 1000000007

int M;

long long solve(long long val, int b){
    if (b == 1) return val%mod;
    if (b&1) return solve(val, b-1)* val%mod;
    return solve(val*val%mod, b/2);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> M;
    long long n, s, res = 0;
    for (int i = 0; i < M; i++){
        cin >> n >> s;
        res += s*solve(n, mod-2) % mod;
        res %= mod;
    }
    cout << res;
    return 0;
}