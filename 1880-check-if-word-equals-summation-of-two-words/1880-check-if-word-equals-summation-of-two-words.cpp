class Solution {
public: 
    int converter(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            ans = ans * 10 + (word[i] - 'a');
        }
        return ans;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return converter(firstWord) + converter(secondWord) == converter(targetWord);
    }
};