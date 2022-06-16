class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int maxLen = 0;
        for (auto& i : rectangles) {
            if (maxLen == min(i[0], i[1]))
                count++;
            else if (maxLen < min(i[0], i[1])) {
                maxLen = min(i[0], i[1]);
                count = 1;
            }
            else
                continue;
        }
        return count;
    }
};