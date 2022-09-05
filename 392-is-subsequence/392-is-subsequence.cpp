class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sizeT = t.size();
        string::iterator it = s.begin();
        for (int i = 0; i < sizeT + 1; i++) {
            if (it == s.end())
                return true;
            if (t[i] == *it)
                it++;
        }
        return false;
    }
};