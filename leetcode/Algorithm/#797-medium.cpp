/**
 * 797. All Paths From Source to Target
 * https://leetcode.com/problems/all-paths-from-source-to-target/
 */

class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        
        visited[0] = true;
        dfs(graph, visited, 0, graph.size(), {0});
        
        return answer;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int idx, int target, vector<int> cur){
        if (target-1 == idx){
            answer.push_back(cur);
            return;
        }
        for (int i = 0; i < graph[idx].size(); i++){
            if (visited[graph[idx][i]]) continue;
            cur.push_back(graph[idx][i]);
            visited[graph[idx][i]] = true;
            dfs(graph, visited, graph[idx][i], target, cur);
            cur.pop_back();
            visited[graph[idx][i]] = false;
        }
    }
};