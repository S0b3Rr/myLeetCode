class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        while(index<n-1)
        {
            if(nums[index]>0)
            {
                index=index+nums[index];
                continue;
            }
            int i=1;
            while(index>=i&&nums[index-i]<=i)
            {
                i++;
            }
            if(i>index)return false;
            index=index-i;
        }
        return true;
    }
};