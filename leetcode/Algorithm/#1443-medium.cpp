/**
 * 1443. Minimum Time to Collect All Apples in a Tree
 * https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
 */

class Solution {
private: 
    unordered_map<int, vector<int>> m;
    int N;
    vector<bool> apple;
    
public:
    int dfs(int node, vector<bool>& visited, int cost){
        if (visited[node]) return 0;
        
        visited[node] = true;
        int child = 0;
        for (int i = 0; i < m[node].size(); i++) {
            child += dfs(m[node][i], visited, 2);
        }
            
        if (child == 0 and !apple[node]) return 0;
        
        return child + cost;
    }    

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        N = n;
        apple = hasApple;
        vector<bool> visited(n, false);
        
        for (auto edge: edges){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, visited, 0);
    }
};