class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> Map;
        int ans = 0, len = 0, start = 0, current = 1;

        for(char ch : s){
            if(Map.find(ch) != Map.end() && start < Map[ch])
                start = Map[ch];
            len = current - start;
            Map[ch] = current++;
            ans = max(len, ans);
        }
    return ans;
    }
};