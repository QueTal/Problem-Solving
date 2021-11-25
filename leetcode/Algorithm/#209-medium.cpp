/*
 * 209. Minimum Size Subarray Sum
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 */    
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX, sum = 0;
        int start = 0, end = 0;
    
        // adding until sum >= target
        // get the length first and 
        // pull the start index until sum < target
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target){
                length = min(length, i - start + 1);
                sum -= nums[start++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};