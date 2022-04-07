class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hashSum(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            hashSum[nums[i]] += nums[i];
        }
        vector<int> dp(10001, 0);
        dp[0] = 0;
        dp[1] = hashSum[1];//there is no 0 in nums
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(dp[i - 2] + hashSum[i], dp[i - 1]);
        }
        return dp[10000];
    }
};