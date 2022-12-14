class Solution {
public:
    int strStr(string haystack, string needle) {
        int kmp[needle.size()];
        int i = 1, j = 0;
        int size = needle.size();
        kmp[0] = 0; //failure table
        while (i < size) {
            if (needle[i] == needle[j]) {
                kmp[i] = j + 1;
                i++;
                j++;
            }
            else if (j > 0) {
                j = kmp[j - 1];
            }
            else {
                kmp[i] = 0;
                i++;
            }
        }
        
        if (!haystack.size())
            return -1;
        
        i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m)
                return i - j;
            else if (i < n && haystack[i] != needle[j]) {
                if (j > 0)
                    j = kmp[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};