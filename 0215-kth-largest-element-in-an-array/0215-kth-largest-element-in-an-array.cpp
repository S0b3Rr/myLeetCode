static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int bucket[20005] = {0};
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i] + 10000]++;
        }
        int flag = k;
        for (int i = 20004; i >= 0; i--) {
            if (bucket[i] == 0)
                continue;
            if (bucket[i] < flag) {
                flag -= bucket[i];
                continue;
            }
            else {
                return i - 10000;
            }
        }
        return INT_MIN;
    }
};