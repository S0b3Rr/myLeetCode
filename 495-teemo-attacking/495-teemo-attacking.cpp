class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ptr = 0;
        int ans = 0;
        while (ptr + 1 < timeSeries.size()) {
            if (timeSeries[ptr + 1] - timeSeries[ptr] > duration)
                ans += duration;
            else
                ans += timeSeries[ptr + 1] - timeSeries[ptr];
            ptr++;
        }
        return ans += duration;
    }
};