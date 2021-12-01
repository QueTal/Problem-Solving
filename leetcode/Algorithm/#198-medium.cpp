/**
 * 198. House Robber
 * https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int m = 0, include = 0, not_include = 0;
        
        for (auto num : nums){
            m = max(include + num, not_include);
            include = not_include;
            not_include = m;
        }
        return m;
    }
};