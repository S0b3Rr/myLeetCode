class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        if (num1 == 0 || num2 == 0)
            return ans;
        ans++;
        if (num1 > num2)
            ans += countOperations(num1 - num2, num2);
        else
            ans += countOperations(num2 - num1, num1);
        return ans;
    }
};