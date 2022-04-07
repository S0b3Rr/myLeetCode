class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //sliding window
        vector<int> pList(26);
        vector<int> ans;
        int size = p.size();
        if (size > s.size())
            return {};
        for (int i = 0; i < size; i++) {
            pList[p[i] - 'a']++;
        }
        for (int i = 0; i < s.size() - size + 1; i++) {
            int j = 0;
            vector<int> sList(26);
            while (j < size) {
                sList[s[i + j] - 'a']++;
                j++;
            }
            if (sList == pList)
                ans.push_back(i);
        }
        return ans;
    }
};