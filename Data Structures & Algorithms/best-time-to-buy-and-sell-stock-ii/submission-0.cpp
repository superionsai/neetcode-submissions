class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; int n = prices.size();
        int iter = 0; int current_buy;
        while (iter < n) {
            current_buy = prices[iter];
            while (iter < n-1 && prices[iter] < prices[iter+1]) 
                iter++;
            max_profit += prices[iter] - current_buy;
            if (prices[iter] == current_buy) iter++;
        }
        return max_profit;
    }
};