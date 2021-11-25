/*
 * 1695. Maximum Erasure Value
 * https://leetcode.com/problems/maximum-erasure-value/
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        unordered_map<int, int> m;
        int cur = 0, answer = 0;
        
        while(right < size){
            m[nums[right]]++;
            cur += nums[right];
            
            while(m[nums[right]] > 1){
                m[nums[left]]--;
                cur -= nums[left];
                left++;
            } 
            answer = max(answer, cur);
            right++;
        }
        return answer;   
    }
};