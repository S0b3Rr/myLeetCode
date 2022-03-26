class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> ss(26);
        vector<int> ts(26);
        for (int i = 0; i < s.size(); i++) {
            ss[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            ts[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (ss[i] != ts[i])
                return i + 'a';
        }
        return 'a';
    }
};