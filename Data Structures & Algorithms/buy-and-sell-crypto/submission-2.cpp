class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_min = prices[0], current_high = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > current_min) current_high = max(current_high, (prices[i]-current_min));
            current_min = min(current_min, prices[i]);
        }
        return current_high;
    }
};
