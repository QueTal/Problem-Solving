/**
 * 1286. Iterator for Combination
 * https://leetcode.com/problems/iterator-for-combination/
 */

class CombinationIterator {
private: 
    string s;
    vector<string> candidates;
    int idx = 0, len;
public:
    void make(int curIdx, string cur){
        if (len == cur.size()){
            candidates.push_back(cur);
            return;
        }
        else if (curIdx >= s.size()) return;
        
        for (int i = curIdx; i < s.size(); i++){
            make(i+1, cur + s[i]);
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength; s = characters;
        make(0, "");
    }
    
    string next() {
        return candidates[idx++];
    }
    
    bool hasNext() {
        return idx < candidates.size();
    }
};
