/**
 * 121. Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, m = 10001;
        
        for (auto price : prices){
            if (m < price) profit = max(profit, price-m);
            else m = price;
        }
        return profit;
    }
};