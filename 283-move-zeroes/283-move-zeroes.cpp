class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next = 0;
        for(int i = 0; i < nums.size(); i++) {
		    if(nums[i])
			    swap(nums[i],nums[next++]);
        }
    }
};