class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            int num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid] : target < nums[0] ? INT_MIN : INT_MAX;
            if (num < target)
                lo = mid + 1;
            else if (num > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};