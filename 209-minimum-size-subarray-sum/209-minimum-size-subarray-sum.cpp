class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int right = 0, left = 0, sum = 0;
        while (right < nums.size() && left <= right) {
            sum += nums[right];
            right++;
            while(sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

