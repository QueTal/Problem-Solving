/*
 * 377. Combination Sum IV
 *  https://leetcode.com/problems/combination-sum-iv/
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int arr[1001] = {0,};
    
        if(*min_element(nums.begin(), nums.end()) > target) return 0;
        
        for(auto num : nums) arr[num] = 1;
        for(int i = 1; i <= target; i++){
            for(auto num: nums){
                if(i-num > 0) arr[i] += arr[i-num];
            }
        }
        return arr[target];
    }
};