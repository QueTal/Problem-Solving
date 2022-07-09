/**
 * 1696. Jump Game VI
 * https://leetcode.com/problems/jump-game-vi/
 */

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int arr[nums.size()];
        
        for (int i = 0; i < nums.size(); i++){
            while (pq.size() and pq.top().second < i-k) 
                pq.pop();
            
            arr[i] = nums[i];
            arr[i] += (pq.size() ? pq.top().first : 0);
            pq.push({arr[i], i});
        }
        
        return arr[nums.size()-1];
    }
};