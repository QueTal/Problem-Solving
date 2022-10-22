/**
 * 219. Contains Duplicate II
 * https://leetcode.com/problems/contains-duplicate-ii/
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, vector<int>> m;
        
        for (int i = 0; i < nums.size(); i++){
            if (m.find(nums[i]) != m.end()){
                m[nums[i]].emplace_back(i);
            }
            else {
                m[nums[i]] = {i};    
            }
        }
        
        for (auto iter = m.begin(); iter != m.end(); iter++){
            if (iter->second.size() < 2) continue;
            
            vector<int> target = iter->second;
            for (int i = 0; i < target.size()-1; i++){
                if (abs(target[i] - target[i+1]) <= k) return true;
            }
        }
        return false;
    }
};