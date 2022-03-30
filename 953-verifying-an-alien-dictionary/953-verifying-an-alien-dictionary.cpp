class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> map;
        for(int i = 0; i < size(order); i++) 
            map[order[i]] = i + 'a';  
        
	    for(auto& word : words)
		    for(auto& w : word) 
                w = map[w];
        
	    return is_sorted(words.begin(), words.end());
    }
};