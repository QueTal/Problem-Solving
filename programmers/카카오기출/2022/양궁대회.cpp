#include <string>
#include <vector>

using namespace std;

int diff = 0;
vector<int> answer(1, -1);

bool checkLower(vector<int>& v){
    for (int i = 10; i >= 0; i--){
        if (v[i] > answer[i]) return true;
        else if (v[i] < answer[i]) return false;
    }
}

void count(vector<int>& info, vector<int>& v){
    int ryan = 0, apeach = 0;
    for (int i = 0; i < 11; i++){
        if (info[i] < v[i]) ryan += 10-i;
        else if (info[i] > 0) apeach += 10-i;
    }
    int d = ryan - apeach;
    if (d > 0 and diff <= d){
        if (diff == d and !checkLower(v)) return;
        diff = d;
        answer = v;
    }
}

void solve(int idx, int arrows, vector<int>& info, vector<int>& v){
    if (idx == 11 or arrows == 0){
        v[10] = arrows;
        count(info, v);
        v[10] = 0;
        return;
    }
    if (arrows > info[idx]){
        v[idx] = info[idx] + 1;
        solve(idx+1, arrows - info[idx] - 1, info, v);
        v[idx] = 0;
    }
    
    solve(idx+1, arrows, info, v);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> v(11, 0);
    solve(0, n, info, v);
    return answer;
}