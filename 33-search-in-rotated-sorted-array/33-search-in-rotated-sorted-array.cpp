class Solution {
public:
    int findPivot(vector<int>& nums){
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while(start < end) {
            mid = start + (end - start)/2;
            if(nums[mid] < nums[end])
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
        
    int findIndex(int start, int end, vector<int>& nums, int target){
        while(start <= end) {
            int mid = start + (end - start)/2;
             
            if(nums[mid] == target)
                 return mid;
            if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid -1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int n = nums.size() - 1;
        if(target >= nums[pivot] && target <=nums[n])
            return findIndex(pivot, n, nums, target);
        else
            return findIndex(0, pivot - 1, nums, target);
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();