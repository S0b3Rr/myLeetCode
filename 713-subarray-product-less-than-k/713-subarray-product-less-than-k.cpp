class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //sliding window
        if(k <= 1) 
            return 0;  
        int prod = 1, ans = 0, left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
            ans += right - left + 1; //puls new possible combinations added when window was slided
        }
        return ans;
    }
};
/*
left and right form the sliding window. For each step, we add the length of this window i.e., right - left + 1 to our counter.

To illustrate, consider a window [a,b] of length 2. Let left and right be equal to 0 and 1 respectively. Now, when we try to extend this window with an incoming element c, we can now form 3 new subarrays with this combination. That is,

a, b, c --> new window
[c], [b, c], [a, b, c]

These are the new subarrays. So now, the right pointer becomes 2. Then, we add (right-left + 1) to our counter. That will now be (2-1+1 = 3), hence 3 new subarrays are added to the counter.*/