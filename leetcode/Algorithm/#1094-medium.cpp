/**
 * 1094. Car Pooling
 * https://leetcode.com/problems/car-pooling/
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001, 0);
        
        for (auto trip : trips){
            v[trip[1]] += trip[0];
            v[trip[2]] -= trip[0];
        }
        
        int load = 0;
        for (int i = 0; i < v.size(); i++){
            if (v[i] == 0) continue;
            load += v[i];
            
            if (load > capacity) return false;
        }
        return true;
    }
};