#include <iostream>

using namespace std;
long long A, B, C;

long long pow (long long a, long long b){
    if (b == 0) return 1;
    else if (b == 1) return a;

    if (b % 2 > 0) return a * pow(a, b-1);
    long long half = pow(a, b/2)%C;
    return (half*half)%C;
}

int main(void){
    cin >> A >> B >> C;
    cout << pow(A, B)%C;
    return 0;
}