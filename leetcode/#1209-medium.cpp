/*
 * 1209. Remove All Adjacent Duplicates in String II
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 */

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int idx = 0, len = s.size();
        bool same = true;
        
        while(idx <= len-k){
            same = true;
            for(int add = 1; add < k; add++){
                if(s[idx] != s[add + idx]){
                    same = false;
                    break;
                }
            }
            
            if(same){
                s = s.substr(0, idx) + s.substr(idx+k);
                idx = 0;
                len = s.size();
                same = true;
                continue;
            }
            idx++;
        }
        return s;
    }
};