class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //sliding window
        vector<int> pList(26);
        vector<int> sList(26);
        vector<int> ans;
        int size = p.size();
        if (size > s.size())
            return {};
        for (int i = 0; i < size; i++) {
            pList[p[i] - 'a']++;
            sList[s[i] - 'a']++;
        }
        if (sList == pList) //basecase
            ans.push_back(0);
        
        for (int i = size; i < s.size(); i++) {
            sList[s[i] - 'a']++;
            sList[s[i - size] - 'a']--;
            
            if (sList == pList)
                ans.push_back(i - size + 1);
        }
        return ans;
    }
};