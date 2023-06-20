/**
 * 2090. K Radius Subarray Averages
 * https://leetcode.com/problems/k-radius-subarray-averages/description/
 */ 

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        long int prefix_sum[nums.size()];
        vector<int> ans(nums.size(), -1);
        if (nums.size() <= 2*k) return ans;
        
        int radius_length = 2*k+1;
        prefix_sum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i-1];
        }

        for (int i = k; i < nums.size(); i++) {
            if ( i + k < nums.size()) {
                ans[i] = ((prefix_sum[i+k] - prefix_sum[i-k] + nums[i-k]) / radius_length);
            }
        }

        return ans;
    }
};