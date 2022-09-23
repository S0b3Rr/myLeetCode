class Solution {
private:
    int currMin = INT_MAX;
public:
    int binaryFind(vector<int>& nums, int lo, int hi) {
        if (lo <= hi) {
            if (lo == hi)
                return lo;
            else if (lo + 1 == hi)
                return lo = nums[lo] < nums[hi] ? lo : hi;
            else {
                int mid = (hi - lo) / 2 + lo;
                currMin = nums[mid] < currMin ? nums[mid] : currMin;
                if (nums[mid] > nums[hi])
                    return binaryFind(nums, mid + 1, hi);
                else
                    return binaryFind(nums, lo, mid - 1);
            }
        }
        return -1;
    }
    
    int findMin(vector<int>& nums) {
        int index = binaryFind(nums, 0, nums.size() - 1);
        return currMin = currMin < nums[index] ? currMin : nums[index];
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();