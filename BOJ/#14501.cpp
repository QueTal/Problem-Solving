#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int dp[16] = { 0 }, pay[16] = { 0 }, time[16] = { 0 };
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {
			if (time[j] + j <= i &&i+time[i]<=N+1) {
				dp[i] = max(dp[i], dp[j]+pay[i]);
			}
		}
	}
    
	int answer = 0;
	for (int i = 0; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	

	return 0;
}