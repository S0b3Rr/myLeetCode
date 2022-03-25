class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = i;
            }
            else{
                map[s[i]] = INT_MAX;
            }
        }
        for(auto& it : map){
            ans = min(it.second, ans);
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};