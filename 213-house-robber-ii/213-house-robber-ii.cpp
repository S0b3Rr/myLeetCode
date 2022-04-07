class Solution {
public:
    int techNine(vector<int>& nums, int left, int right) {
        int pre = 0, cur = 0;//pre is i - 2, curr is i - 1, 
        for (int i = left; i <= right; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return max(techNine(nums, 0, nums.size() - 2), techNine(nums, 1, nums.size() - 1));
    }
};