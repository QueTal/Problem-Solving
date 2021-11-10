/**
 * 122. Best Time to Buy and Sell Stock II
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, len = prices.size();
        
        for (int i = 0; i < len-1; i++){
            if (prices[i] <= prices[i+1]) profit += prices[i+1]-prices[i];
        }
        return profit;
    }
};