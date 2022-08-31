class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumR = 0;
        int sumL = 0;
        int size = nums.size();
        for (auto i : nums)
            sumR += i;
        for (int i = 0; i < size; i++) {
            if (sumR - nums[i] == sumL)
                return i;
            sumL += nums[i];
            sumR -= nums[i];
        }
        return -1;
    }
};