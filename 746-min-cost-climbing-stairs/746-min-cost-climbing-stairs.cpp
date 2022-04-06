class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < size; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[size - 1], dp[size - 2]);
    }
};
