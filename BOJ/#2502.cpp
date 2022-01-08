#include <iostream>

using namespace std;

int D, K;
int a[31], b[31];

int main(void){
    cin >> D >> K;

    a[1] = 1; a[2] = 0;
    b[1] = 0; b[2] = 1;
    for (int i = 3; i <= D; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }

    for (int i = K/b[D]; i > 0; i--){
        if ((K-i*b[D])%a[D] == 0) {
            cout << (K-i*b[D])/a[D] << endl;
            cout << i << endl;
            break;
        }
    }
    return 0;
}