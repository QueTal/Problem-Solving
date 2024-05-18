/**
 * 2441. Largest Positive Integer That Exists With Its Negative
 * https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
 */ 

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map <int, int> m;

        for (int num: nums) {
            m[num] += 1;
        }
        sort(nums.begin(), nums.end());

        for (int num: nums) {
            if (num > 0) continue;
            int posNum = abs(num);
            if (m.find(posNum) != m.end()) return posNum;
        }
        return -1;
    }
};