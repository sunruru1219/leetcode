class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0; int total = 0;
        int min = prices[0];
        int max = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < max) {
                min = prices[i];
                max = prices[i];
                total+=profit;
                profit = 0;
            }
            if (prices[i] > max) {
                max = prices[i];
                int p = max-min;
                if (p > profit) profit = p;
            }
            if (i == prices.size()-1)
                total+=prices[i]-min;
        }
        return total;
    }
};