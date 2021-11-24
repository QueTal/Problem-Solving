/**
 * 986. Interval List Intersections
 * https://leetcode.com/problems/interval-list-intersections/
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int Asize = A.size(), Bsize = B.size();
        int i = 0, j = 0;
        while(i < Asize and j < Bsize){
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if( start <= end )   result.push_back({start, end});
            (A[i][1] < B[j][1]) ? i++ : j++;
        }
        return result;
    }
};