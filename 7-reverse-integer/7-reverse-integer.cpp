class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();