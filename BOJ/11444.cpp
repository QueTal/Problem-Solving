#include<iostream>
#include<vector>

using namespace std;

const long long mod = 1000000007;
long long n;

vector< vector<long long> > multiple (vector< vector<long long> >& a, vector< vector<long long> >& b){
	vector< vector<long long> > c(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= mod;
		}
	return c;	
}

int main(){
	cin >> n;

	vector< vector<long long> > ans = {{1,0}, {0,1}};
	vector< vector<long long> > a = {{1,1}, {1,0}};

	while (n > 0){
		if (n % 2 == 1) ans = multiple(ans, a);
		a = multiple(a, a);
		n /= 2;
	}
	
	cout << ans[0][1] << '\n';
}