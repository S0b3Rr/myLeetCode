class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count1 = 0;
        if (n < 0)
            return false;;
        while(n) {
            n = n & (n-1);
            count1++;
        }
        if(count1 == 1) 
            return true;
        else
            return false;
    }
};