/**
 * 451. Sort Characters By Frequency
 * https://leetcode.com/problems/sort-characters-by-frequency/
 */

class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;    
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> m;
        
        for (auto c : s) m[c]++;
        
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        
        string res = "";
        for(auto vv : v){
            for(int i = 0; i < vv.second; i++) res += vv.first;
        }
        return res;
    }
};