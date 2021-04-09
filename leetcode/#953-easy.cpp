/*************************************
* 953. Verifying an Alien Dictionary *
*************************************/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        vector<string> v, temp;
        int cnt = 1;
        
        for(auto o : order) m[o] = cnt++;
        for(int i = 0; i < words.size() -1; i++){
            int alen = words[i].size();
            int blen = words[i+1].size();
            int len = alen > blen ? blen : alen;
            
            for(int j = 0; j < len; j++){
                if(m[words[i][j]] > m[words[i+1][j]]){
                    return false;
                }
                else if(m[words[i][j]] < m[words[i+1][j]]) break;
            }
            if(words[i][len-1] == words[i+1][len-1] and alen > blen){
                return false;
            }
        }
        return true;
    }
};
