#include <iostream>

using namespace std;

int N, L;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> L;
    
    int n = L; 
    while (1){
        int temp = N - (n*(n-1))/2;
        if (temp < 0 or n > 100) { cout << -1 << endl; break; }
        if (temp % n == 0) {
            int start = temp / n;
            for (int i = start; i < start + n; i++) cout << i << " ";

            break;
        }
        n++;
    }
    return 0;
}
