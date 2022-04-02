class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        if (x > y)
            return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = x;
        while (lo <= hi) {
            int partitionX = (lo + hi) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            //if partition is the  left-most of an array, maxleft = INT_MIN
            //if partition is the right-most of an array, maxleft = INT_MAX
            int maxLeftX, minRightX, maxLeftY, minRightY;
            if (partitionX == 0)
                maxLeftX = INT_MIN;
            else
                maxLeftX = nums1[partitionX - 1];
            
            if (partitionX == x)
                minRightX = INT_MAX;
            else
                minRightX = nums1[partitionX];
            
            if (partitionY == 0)
                maxLeftY = INT_MIN;
            else
                maxLeftY = nums2[partitionY - 1];
            if (partitionY == y)
                minRightY = INT_MAX;
            else
                minRightY = nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0)
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                else
                    return (double)max(maxLeftX, maxLeftY);
            }
            //adjusting the correct position to meet maxLeftX <= minRightY && maxLeftY <= minRightX
            else if (maxLeftX > minRightY)
                hi = partitionX - 1;
            else
                lo = partitionX + 1;
        }
        return -1;
    }
    //inspired by: https://www.youtube.com/watch?v=LPFhl65R7ww
};