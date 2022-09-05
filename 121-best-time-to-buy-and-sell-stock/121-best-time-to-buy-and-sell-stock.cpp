class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        int size = prices.size();
        for (int i = 0; i < size; i++) {
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i] - buy);
        }
        return sell;
    }
};