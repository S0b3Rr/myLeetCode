static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        return longestCommonSubsequence(s1, s2);
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int dp[s1.size() + 1][s2.size() + 1];
        int b[s1.size() + 1][s2.size() + 1];
        for (int i = 0; i < s1.size() + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < s2.size() + 1; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i < s1.size() + 1; i++) {
            for (int j = 1; j < s2.size() + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    b[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] >= dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                    b[i][j] = dp[i][j] == dp[i - 1][j] ? 2 : 3;
                }
            }
        }
        
        int i = s1.size(), j = s2.size();
        int ans = 0;
        while (i > 0 && j > 0) {
            if (b[i][j] == 1) {
                ans++;
                i--;
                j--;
            }
            else if (b[i][j] == 2) {
                i--;
            }
            else
                j--;
        }
        return ans;
    }
};