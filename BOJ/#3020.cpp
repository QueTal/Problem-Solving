#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    
    vector<int> top(n/2, 0), bot(n/2, 0);
    for(int i  = 0; i < n/2; i++) cin >> bot[i] >> top[i];
    
    sort(bot.begin(), bot.end()); sort(top.begin(), top.end());

    int cnt = 1, ans = 987654231;
    for (int i = 1; i <= m; i++){
        int cand = bot.size() - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
        cand += top.size() - (upper_bound(top.begin(), top.end(), m-i) - top.begin());

        if (cand == ans) cnt++;
        else if (cand < ans){
            ans = cand;
            cnt = 1;
        }
    }
    cout << ans << " " << cnt;
    return 0;
}