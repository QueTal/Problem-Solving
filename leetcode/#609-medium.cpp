/*
 * 609. Find Duplicate File in System
 * https://leetcode.com/problems/find-duplicate-file-in-system/
 */

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> answer;
        
        for(auto path: paths){
            string dir = "", file = "", content = "";
            int i = 0, j;
            while(path[i] != ' ') i++;
            dir = path.substr(0, i);
        
            while(i++ < path.size()){
                j = i;
                while(path[i] != '(') i++;
                file = path.substr(j, i-j);
                
                j = i;
                while(path[i++] != ')');
                content = path.substr(j, i-j);
                
                m[content].emplace_back(dir+'/'+file);
            }
        }
        
        for(auto iter = m.begin(); iter != m.end(); iter++){
            if(iter->second.size() > 1) answer.emplace_back(iter->second);
        }
        return answer;
    }
};