class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int reachable = 0;
        
        if (nums[0] == 0 && size > 1) //base condition
            return false;
        
        for (int i = 0; i < size; i++) {
            if (i > reachable)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        
        return true;
    }
};