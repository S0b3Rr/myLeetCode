class Solution {
public:
    int climbStairs(int n) {
        //optimize: recursive -> dp -> fibonacci dp
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
        //inspired by: https://www.youtube.com/watch?v=RrFg9SZ8VoM
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();