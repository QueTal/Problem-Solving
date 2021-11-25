/**
 * 2012. Sum of Beauty in the Array
 * https://leetcode.com/problems/sum-of-beauty-in-the-array/
 */

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> left, right;
        int answer = 0;
        
        left = right = nums;
        
        // set left
        for (int i = 1; i < nums.size(); i++) left[i] = max(left[i-1], nums[i-1]);
        
        // set right
        for (int i = nums.size()-2; i >= 0; i--) right[i] = min(right[i+1], nums[i+1]);
        
        for (int i = 1; i < nums.size()-1; i++){
            if (left[i] < nums[i] and nums[i] < right[i]) answer += 2;
            else if (nums[i-1] < nums[i] and nums[i] < nums[i+1]) answer += 1;
        }
        return answer;
    }
};
