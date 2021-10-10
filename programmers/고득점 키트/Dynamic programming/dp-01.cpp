/* 
 * https://programmers.co.kr/learn/courses/30/lessons/42895
 * level : 3 / N으로 표현
 */

#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = 0, res = 0;
    vector<set<int>> v(8);
    
    if(N == number) return 1;
    for(int i = 0; i < 8; i++){
        res += pow(10, i) * N;
        v[i].insert(res);
    }
    
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int x : v[j]){
                for(int y : v[i-j-1]){
                    v[i].insert(x+y);
                    v[i].insert(x-y);
                    v[i].insert(x*y);
                    if(y) v[i].insert(x/y);
                }
            }
            if(v[i].find(number)!=v[i].end()){
                return i+1;
            }
        }
    }
    return -1;
}