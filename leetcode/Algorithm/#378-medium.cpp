/*
 * 378. Kth Smallest Element in a Sorted Matrix
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 */ 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = matrix.size();
        int start = matrix[0][0], end = matrix[size-1][size-1];
        
        while(start < end){
            int count = 0;
            int mid = start + (end - start) / 2;
            int row = 0, col = size-1;
            
            for(int row = 0; row < size; row++){
                while( col >= 0 and mid < matrix[row][col]){
                    col--;
                }
                count += col+1;
                
            }
            
            if(count < k) start = mid + 1;
            else end = mid;
        }
        return start;
    }
};