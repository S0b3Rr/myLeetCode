class Solution {
public:
    string freqAlphabets(string s) {
        int size = s.length();
        string ans = "";
        int i = 0;
        while(i < size) {
            if(i + 2 < size && s[i + 2] == '#') {
                int ss = (s[i]-'0')*10 + (s[i+1]-'0');
                ans += char(ss+'a'-1);
                i += 3;
            }
            else {
                ans += char(s[i]-'0'-1+'a');
                i++;
            }
        }
        return ans;
    }
};