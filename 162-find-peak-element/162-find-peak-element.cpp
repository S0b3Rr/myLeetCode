class Solution {
public:
    int binaryFind(vector<int>& nums, int lo, int hi) {
        if (lo <= hi) {
            if (lo == hi)
                return lo;
            else if (lo + 1 == hi)
                return lo = nums[lo] > nums[hi] ? lo : hi;
            
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                return binaryFind(nums, mid + 1, hi);
            else
                return binaryFind(nums, lo, mid - 1);
        }
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        //if ()
        return binaryFind(nums, 0, nums.size() - 1);
    }
};