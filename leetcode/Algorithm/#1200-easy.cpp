/**
 * 1200. Minimum Absolute Difference
 * https://leetcode.com/problems/minimum-absolute-difference/
 */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int m = 987654321;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size()-1; i++){
            if (m == arr[i+1]-arr[i]) res.push_back({arr[i],arr[i+1]});
            else if (m > arr[i+1]-arr[i]) {
                m = arr[i+1]-arr[i];
                res.clear();
                res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};