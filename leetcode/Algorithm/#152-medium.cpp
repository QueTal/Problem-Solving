/**
 * 152. Maximum Product Subarray
 * https://leetcode.com/problems/maximum-product-subarray/
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = 0, M = 0, cur = 0;
        
        m = M = cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0){
                M = max(M * nums[i], nums[i]);
                m = min(m * nums[i], nums[i]);
            }   
            else {
                int temp = max(m * nums[i], nums[i]);
                m = min(nums[i] * M, nums[i]);
                M = temp;
            }
            cur = max(cur, M);
        }
        return cur;
    }
};