#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, answer = 0;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++){
        int val = 0;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    do{
        int sum = 0;
        for(int i = 0; i < v.size()-1; i++){
            sum += abs(v[i] - v[i+1]);
        }
        
        answer = max(answer, sum);
        
    } while(next_permutation(v.begin(), v.end()));

    cout << answer << endl;
    return 0;
}