#include <iostream>

using namespace std;

long long N, B;
long long ans[5][5], input[5][5], temp[5][5];

void solve(long long a[5][5], long long b[5][5]){
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			temp[i][j] = 0; 
			for (int k = 0; k < N; k++) temp[i][j] += (a[i][k] * b[k][j]);
			temp[i][j] %= 1000;
		}
    }

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = temp[i][j];
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> B;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> input[i][j];
        }
        ans[i][i] = 1;
    }

    while (B){
        if (B%2 == 1){
            solve(ans, input);
        }
        solve(input, input);
        B /= 2;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}