static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

class Solution {
public: 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int numIntervals = 0;
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>>::iterator prev = intervals.begin();
        vector<vector<int>>::iterator curr = intervals.begin() + 1;
        while (curr != intervals.end()) {
            if ((*curr)[0] < (*prev)[1]) {
                numIntervals++;
            }
            else {
                prev = curr;
            }
            curr++;
        }
        return numIntervals;
    }
};