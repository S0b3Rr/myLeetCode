class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxW = INT_MIN;
        int size = height.size();
        while (i < j) {
            int curr;
            curr = min(height[i], height[j]);
            maxW = max(maxW, curr * (j - i));
            if (height[i] < height[j])
                i++;
            else if (height[i] > height[j])
                j--;
            else {
                i++;
                j--;
            }
        }
        return maxW;
    }
};