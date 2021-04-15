/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42746
 * level : 2 / 가장 큰 수
 * ******************************************************* */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool comp(string a, string b){
    return a+b> b+a;
}

string solution(vector<int> numbers) {
    vector<string> v;
    string answer = "";
    
    for(auto num : numbers) v.push_back(to_string(num));
    sort(v.begin(), v.end(), comp);
    
    if(v[0] == "0") return "0";
    for(auto c: v) answer+=c;
    return answer;
}