class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        
        while (i < size) {
            long correctIndex = ((long)nums[i])-1;
            if (nums[i] > 0 && nums[i] <= size && nums[correctIndex] != nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = tmp;
            } else
                i++;
        }
        
        for (long i = 0; i < size; i++)
            if (nums[i] != i + 1)
                return i + 1;
                
        return size + 1;
    }
};