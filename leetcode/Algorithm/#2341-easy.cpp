/**
 * 2341. Maximum Number of Pairs in Array
 * https://leetcode.com/problems/maximum-number-of-pairs-in-array/
 */

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (auto num : nums) m[num]++;
        
        int formed = 0, l = nums.size();
        for (auto iter = m.begin(); iter != m.end(); iter++){
            formed += iter->second / 2;
        }
        
        return {formed, l - 2*formed};
    }
};