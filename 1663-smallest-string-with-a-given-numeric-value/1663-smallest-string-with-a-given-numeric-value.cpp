class Solution {
public:
    string getSmallestString(int n, int k) {
        //ascii 'a' decimai = 97
        vector<int> strring(n, k / n); //均摊 之后把数字向右推
        vector<int>::iterator ptr = strring.begin() + n - 1;
        int remainder = k % n;
        while (remainder > 0) {
            if (*ptr + remainder <= 26) {
                *ptr += remainder;
                break;
            }
            else {
                remainder = remainder + *ptr - 26;
                *ptr = 26;
                ptr--;
            }
        }
        
        // two pointers
        int i = 0, j = n - 1;
        while (i < j) {
            int remain = 26 - strring[j];
            if (remain >= strring[i] - 1) {
                strring[j] = strring[j] + strring[i] - 1;
                strring[i] = 1;
            }
            else {
                strring[i] -= remain;
                strring[j] += remain;
            }
            if (strring[i] == 1)
                i++;
            if (strring[j] == 26)
                j--;
        }
        
        string ans = "";
        for (auto& s : strring) {
            ans += char(s + 96);
        }
        return ans;
        
    }
};