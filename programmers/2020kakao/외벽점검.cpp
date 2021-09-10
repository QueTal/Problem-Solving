#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, answer = 987654321;
vector<int> Weak;
vector<int> Dist;

void solve(int cnt, int cur, int visited){
    if (cnt > Dist.size()) return;
    if (cnt >= answer) return;
    
    for (int i = 0; i < Weak.size(); i++){
        int next = (cur + i) % Weak.size();
        int diff = Weak[next] - Weak[cur];
        if (next < cur) diff += N;
        
        if (Dist[Dist.size()-cnt] < diff) break;
        
        visited |= (1 << next);
    }
    // 다 돌았는지 확인
    if (visited == (1 << Weak.size()) - 1) {
        answer = min(answer, cnt);
        return;
    }
    // 다음 시작 점에서 시작
    for (int i = 0; i < Weak.size(); i++){
        if (visited & (1 << i)) continue;
        solve(cnt+1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n; Weak = weak; Dist = dist;
    sort(Dist.begin(), Dist.end());
    for(int i = 0; i < Weak.size(); i++){
        solve(1, i, 0);
    }
    return answer == 987654321 ? -1 : answer;
}