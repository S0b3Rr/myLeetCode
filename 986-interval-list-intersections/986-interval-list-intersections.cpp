class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int size1 = firstList.size(), size2 = secondList.size();
        while (i < size1) {
            while (j < size2) {
                int leftBound = max(firstList[i][0], secondList[j][0]);
                int rightBound = min(firstList[i][1], secondList[j][1]);
                j++;
                if (leftBound > rightBound)
                    continue;
                ans.push_back({leftBound, rightBound});
            }
            i++;
            j = 0;
        }
        return ans;
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();