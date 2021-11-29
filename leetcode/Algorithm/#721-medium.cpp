/**
 * 721. Accounts Merge
 * https://leetcode.com/problems/accounts-merge/
 */

class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adj;
    
    void dfs(vector<string>& merged, string& email){
        visited.insert(email);
        
        merged.push_back(email);
        
        for (auto a : adj[email]){
            if (visited.find(a) != visited.end()) continue;
            dfs(merged, a);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto account : accounts){
            int sz = account.size();
            
            for (int i = 2; i < sz; i++){
                adj[account[1]].push_back(account[i]);
                adj[account[i]].push_back(account[1]);
            }
        }
        
        vector<vector<string>> merged;
        for (auto account : accounts){
            string name = account[0];
            string first = account[1];
            
            if (visited.find(first) == visited.end()){
                vector<string> temp;
                temp.push_back(name);
                dfs(temp, first);
                sort(temp.begin()+1, temp.end());
                merged.push_back(temp);
            }
        }
        
        return merged;
    }
};