class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;        
        map<int, char> ss, tt;
        for (int i = 0; i < s.size(); i++) 
            ss[s[i]]++;
        for (int i = 0; i < t.size(); i++) 
            tt[t[i]]++;
        auto ptrs = ss.begin();
        auto ptrt = tt.begin();
        while (ptrs != ss.end() && ptrt != tt.end()) {
            if (ptrs -> first != ptrt -> first || ptrs -> second != ptrt -> second)
                return false;
            ptrs++;
            ptrt++;
        }

        return true;
    }
};