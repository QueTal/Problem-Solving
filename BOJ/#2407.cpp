#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, R;
string factorial[101][101];

string Add(string a, string b){
    int sum = 0;
    string result;

    while (!a.empty() or !b.empty() or sum) {
        if (!a.empty()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int N, int R){
    if (N == R or R == 0) return "1";

    string& res = factorial[N][R];
    if (res != "") return res;

    res = Add(combination(N-1, R-1), combination(N-1, R));
    return res;
}

int main(void){
    cin >> N >> R;
    cout << combination(N, R);
    return 0;
}