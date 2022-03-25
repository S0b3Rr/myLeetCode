class Solution {
public:
    bool match(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        //sliding window + vector implemented hash table
        if (s1.size() > s2.size())
            return false;
        vector<int> smaller(26);
        vector<int> bigger(26);
        for (int i = 0; i < s1.size(); i++) {
            smaller[s1[i] - 'a']++;
            bigger[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (match(smaller, bigger))
                return true;
            bigger[s2[i + s1.size()] - 'a']++;
            bigger[s2[i] - 'a']--;
        }
        return match(smaller, bigger);
    }
};