#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void){
    int num, cnt = 0;
    string target = "";
    unordered_map<string, int> m;

    cin >> num;
    for(int i = 0; i < num; i++){
        string name;
        cin >> name;
        m[name]++;
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(cnt < iter->second) {
            cnt = iter->second;
            target = iter->first;
        }
        else if(cnt == iter->second and target > iter->first){
            target = iter->first;
        }
    }
    cout << target;
    return 0;
}