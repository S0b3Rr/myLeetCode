static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //str1 -> x, str2 -> y
        int dp[str1.size() + 1][str2.size() + 1];
        int b[str1.size() + 1][str2.size() + 1]; //for backtracking
        for (int i = 0; i < str1.size() + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < str2.size() + 1; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < str1.size() + 1; i++) {
            for (int j = 1; j < str2.size() + 1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    b[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + 1 <= dp[i][j - 1] + 1 ? dp[i - 1][j] + 1 : dp[i][j - 1] + 1;
                    b[i][j] = dp[i][j] == dp[i - 1][j] + 1 ? 2 : 3;
                }
            }
        }
        
        //backTracking
        string ans = "";
        int i = str1.size(), j = str2.size();
        while (i != 0 || j != 0) {
            if (b[i][j] == 1) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (b[i][j] == 2) {
                ans.push_back(str1[i - 1]);
                i--;
            }
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
            if (i == 0 && j == 0)
                break;
            if (i == 0) {
                while (j != 0) {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
                break;
            }
            if (j == 0) {
                while (i != 0) {
                    ans.push_back(str1[i - 1]);
                    i--;
                }
                break;
            }
        }
        // cout << ans << endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};