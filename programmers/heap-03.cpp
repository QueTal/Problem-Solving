/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42628
 * level : 3 / 이중우선순위큐
 * ******************************************************* */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> temp;
    
    for(string str : operations){
        char op = str[0];
        int num = stoi(str.substr(1));
        
        if(op == 'I') temp.push_back(num);
        else {
            int target = 0;
            if(temp.size() == 0) continue;
            
            if(num == 1) target = *max_element(temp.begin(), temp.end());
            else target = *min_element(temp.begin(), temp.end());
            
            for(auto iter = temp.begin(); iter != temp.end(); iter++){
                if(*iter==target) {
                    temp.erase(iter);
                    break;
                }
            }
        }
    }
    if(temp.size() == 0) return {0,0};
    int M = *max_element(temp.begin(), temp.end());
    int m = *min_element(temp.begin(), temp.end());
    return {M,m};
}