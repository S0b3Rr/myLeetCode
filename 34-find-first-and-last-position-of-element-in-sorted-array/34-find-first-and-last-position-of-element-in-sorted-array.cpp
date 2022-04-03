class Solution {
public:
    int findTarget(vector<int>& nums, int target, int lo, int hi) {
        if (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                return findTarget(nums, target, mid + 1, hi);
            else
                return findTarget(nums, target, lo, mid - 1);
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //binary search
        vector<int> ans = {-1, -1};
        
        int index = findTarget(nums, target, 0, nums.size() - 1);
        if (index == -1)
            return ans;
        else {
            int i = 0, j = 0;
            while (nums[index + i] == target && index + i + 1 < nums.size()) {
                if (index + i + 1 >= nums.size())
                    break;
                if (nums[index + i + 1] == target)
                    i++;
                else
                    break;
            }
            while (nums[index - j] == target && index - j - 1 >= 0) {
                if (index - j <= 0)
                    break;
                if (nums[index - j - 1] == target)
                    j++;
                else
                    break;
            }

            ans[0] = index - j;
            ans[1] = index + i;
        }
        return ans;
    }
};