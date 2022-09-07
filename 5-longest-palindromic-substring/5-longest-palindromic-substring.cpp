class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        
        int size = s.size();
        int ptr = 0;
        int startIndex = 0, length = 0;
        while (ptr < size) {
            int ptrL = ptr, ptrR = ptr;
            while (s[ptrR] == s[ptrR + 1] && ptrR < size) {
                ptrR++;
            }
            ptr = ptrR + 1;
            while (ptrL > 0 && ptrR < size && s[ptrL - 1] == s[ptrR + 1]) {
                ptrL--;
                ptrR++;
            }
            if (length < ptrR - ptrL) {
                startIndex = ptrL;
                length = ptrR - ptrL;
            }
        }
        return s.substr(startIndex, length + 1);
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

