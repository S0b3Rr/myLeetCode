class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int isomorphicTableS[128] = {0};
        int isomorphicTableT[128] = {0};
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (isomorphicTableS[s[i]] != isomorphicTableT[t[i]])
                return false;
            isomorphicTableS[s[i]] = i + 1;
            isomorphicTableT[t[i]] = i + 1;
        }
        return true;
    }
};