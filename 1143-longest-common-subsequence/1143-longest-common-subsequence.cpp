static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:  
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size() + 1][text2.size() + 1];
        int backTrack[text1.size() + 1][text2.size() + 1];
        for (int i = 0; i < text1.size() + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < text2.size() + 1; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i < text1.size() + 1; i++) {
            for (int j = 1; j < text2.size() + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    backTrack[i][j] = 1;
                }
                else if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    backTrack[i][j] = 2;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    backTrack[i][j] = 3;
                }
            }
        }
        
        //backtracking
        int i = text1.size(), j = text2.size();
        int ans = 0;
        while (i > 0 && j > 0) {
            if (backTrack[i][j] == 1) {
                i--;
                j--;
                ans++;
            }
            else if (backTrack[i][j] == 2)
                i--;
            else //(backTrack[i][j] == 3)
                j--;
        }
        return ans;
    }
};