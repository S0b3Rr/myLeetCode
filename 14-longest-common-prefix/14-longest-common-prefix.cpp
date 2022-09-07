class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //string ans = "";
        int str_idx = 0;
        int minLength = 500;
        for (int j = 0; j < strs.size(); j++)
            minLength = std::min(minLength, int(strs[j].size()));
        int ptr = 0;
        while (ptr < minLength) {
            char sample = strs[0][ptr];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][ptr] != sample)
                    goto End;
            }
            ptr++;
        }
        End:
        return strs[0].substr(0, ptr);
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();