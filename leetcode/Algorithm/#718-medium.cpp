/*
 * 718. Maximum Length of Repeated Subarray
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/
 */ 

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> v (len1+1,  vector<int>(len2+1, 0));
        int m = 0;
        
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if (nums1[i-1] == nums2[j-1]) v[i][j] = v[i-1][j-1] + 1; 
                else v[i][j] = 0;
                m = max(m, v[i][j]);
            }
        }
        return m;
    }
};