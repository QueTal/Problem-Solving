/**
 * 228. Summary Ranges
 * https://leetcode.com/problems/summary-ranges/
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        long start, end;       
        string temp;
        
        if(nums.size() == 0) return res;
        start = end = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - end > 1){
                temp = to_string(start) + "->" + to_string(end);
                if(start == end) temp = to_string(start);
                res.push_back(temp);
                start = nums[i]; end = nums[i];
            }
            else{    
                //start = min(start, nums[i]);
                end = max(end, nums[i]);               
            }
        }
        start == end ? temp = to_string(start) : temp = to_string(start) + "->" + to_string(end);
        res.push_back(temp);
        return res;
    }
    long min(long a, long b){
        return a > b? b : a;
    }
    
    long max(long a, long b){
        return a > b? a : b;
    }
};