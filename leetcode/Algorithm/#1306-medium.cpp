/**
 * 1306. Jump Game III
 * https://leetcode.com/problems/jump-game-iii/
 */

class Solution {
public:
    bool answer = false;
    bool canReach(vector<int>& arr, int start) {
        dfs(arr, start);
        return answer;
    }
    
    void dfs(vector<int>& arr, int cur){
        if (answer or cur < 0 or cur >= arr.size() or arr[cur] < 0) return;
        
        if (arr[cur] == 0) {
            answer = true;
            return;
        }
        
        arr[cur] *= -1;
        dfs(arr, cur+arr[cur]);
        dfs(arr, cur-arr[cur]);
    }
};