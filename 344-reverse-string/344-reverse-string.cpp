class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, j = s.size() - 1;
        while (l <= j) {
            swap(s[l], s[j]);
            l++;
            j--;
        }
    }
};