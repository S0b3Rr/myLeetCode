class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size())
            return 0;
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i + 1] = max(nums[i] + dp[i - 1], dp[i]);
        }
        return dp[nums.size()];
    }
};