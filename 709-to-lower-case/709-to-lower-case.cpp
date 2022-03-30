class Solution {
public:
    string toLowerCase(string s) {
        //upper ascii: 65-90
        //lower ascii: 97-122
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 32;
        }
        return s;
    }
};