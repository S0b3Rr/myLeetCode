static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpCount = 0;
        int currIndex = 0;
        int nextIndex = INT_MIN;
        int i = 0;
        while (currIndex < nums.size() - 1) {
            nextIndex = max(nextIndex, i + nums[i]);
            if (i == currIndex) {
                currIndex = nextIndex;
                jumpCount++;
            }
            i++;
        }
        return jumpCount;
    }
};