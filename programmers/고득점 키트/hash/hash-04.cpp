
/* *********************************************************
 * https://programmers.co.kr/learn/courses/30/lessons/42579
 * level : 3 / 베스트앨범
 * ******************************************************* */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

static bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first) return true;
    else if(a.first == b.first){
        if(a.second < b.second) return true;
        else return false;
    }
    else return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int ,int>>> infos;
    vector<pair<int, string>> v; 
    vector<bool> isChecked(genres.size(), false);
    
    for(int i = 0; i < genres.size(); i++){
        string s = genres[i];
        int times = 0;
        vector< pair<int,int> > temp;
        // 같은 장르 횟수 더하기
        for(int j = 0; j < genres.size(); j++){
            if(!isChecked[j] and s == genres[j]){
                times += plays[j]; 
                isChecked[j] = true;
                temp.push_back({plays[j], j});
            } 
        }
        sort(temp.begin(), temp.end(), comp);
        infos[genres[i]] = temp;
        // total play time, genres
        if(times!=0)v.push_back({times, s});
    }
    // 재생횟수로 장르 순서 정하기
    sort(v.begin(), v.end(), greater<>());
    
    
    for(int i = 0; i < v.size(); i++){
        if(infos[v[i].second].size() == 1){
            answer.push_back(infos[v[i].second][0].second);
        }
        else {
            answer.push_back(infos[v[i].second][0].second);
            answer.push_back(infos[v[i].second][1].second);
        }
    }   
    return answer;
}