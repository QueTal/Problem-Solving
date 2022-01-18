#include <iostream>

using namespace std;

int A, B;

int main(void) {
    cin >> A >> B;
    
    int cnt = 1;
    while (true) {
        if (B%10==1){
            cnt++;
            B--; B/=10;
        }
        else if (B%2 == 0){
            cnt++;
            B/=2;
        }
        else if (B%2 == 1){
            cnt = -1;
            break;
        }

        if (A >= B) {
            if (A > B) cnt = -1;
            break;
        }
    }
    cout << cnt;
    return 0;
}