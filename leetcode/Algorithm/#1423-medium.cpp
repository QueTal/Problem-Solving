/*
 * 1423. Maximum Points You Can Obtain from Cards
 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0, partialSum = 0, tempSum;
        int size = cardPoints.size(), len = size - k;
        int start = 0, end = len;
        
        for(auto card: cardPoints) totalSum += card;
        for(int i = 0; i < len; i++) partialSum += cardPoints[i];
        tempSum = partialSum;
        
        while(end < size){
            tempSum = tempSum - cardPoints[start] + cardPoints[end];
            if(tempSum < partialSum) partialSum = tempSum;
            start++; end++;
        }
        
        return totalSum - partialSum;
    }
};