class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int& price : prices) {
            buy = min(buy, price);
            profit = max(profit, price - buy);
        }
        return profit;
    }
};