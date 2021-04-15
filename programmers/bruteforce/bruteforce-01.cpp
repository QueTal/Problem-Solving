/* 
 * https://programmers.co.kr/learn/courses/30/lessons/42840
 * level : 1 / 모의고사
 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    int ca = 0, cb = 0, cc = 0;
    
    for(int i = 0; i < answers.size(); i++){
        ca += (answers[i] == a[i%5]) ? 1 : 0;
        cb += (answers[i] == b[i%8]) ? 1 : 0;
        cc += (answers[i] == c[i%10]) ? 1 : 0;
    }
    int m = max(ca, max(cb, cc));
    if(m == ca) answer.push_back(1);
    if(m == cb) answer.push_back(2);
    if(m == cc) answer.push_back(3);
    
    return answer;
}
