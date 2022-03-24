class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxx = INT_MIN;
        int curr = 0;
        int size = accounts[0].size();
        for (auto& ac: accounts) {
            for (int i = 0; i < size; i++) {
                curr += ac[i];
            }
            maxx = max(curr, maxx);
            curr = 0;
        }
        return maxx;
    }
};