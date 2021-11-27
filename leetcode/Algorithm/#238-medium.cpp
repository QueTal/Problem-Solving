/**
 * 238. Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        vector<int> left(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++){
            left[i] = nums[i-1] * left[i-1];
        }
        
        int R = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            left[i] *= R;
            R *= nums[i];
        }
        return left;
    }
};