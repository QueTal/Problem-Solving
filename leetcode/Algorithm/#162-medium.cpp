/*
 * 162. Find Peak Element
 * https://leetcode.com/problems/find-peak-element/
 */


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<long long> v(nums.size()+2, -2147483649);
        
        for(int i = 1; i <= nums.size(); i++){
            v[i] = nums[i-1];
        }
        for(int i = 1; i < v.size()-1; i++){
            if (v[i] > v[i+1] and v[i] > v[i-1]) return i-1;
        }
        
        return -1;
    }
};