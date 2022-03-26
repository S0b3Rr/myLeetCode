class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        auto ptr1 = word1.begin();
        auto ptr2 = word2.begin();
        while (ptr1 != word1.end() && ptr2 != word2.end()) {
            ans += *ptr1;
            ptr1++;
            ans += *ptr2;
            ptr2++;
        }
        while (ptr1 != word1.end()) {
            ans += *ptr1;
            ptr1++;
        }
        while (ptr2 != word2.end()) {
            ans += *ptr2;
            ptr2++;
        }
        return ans;
    }
};