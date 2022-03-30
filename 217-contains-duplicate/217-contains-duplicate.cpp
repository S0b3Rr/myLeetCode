class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& n : nums) {
            if (!s.insert(n).second)
                return true;
        }
        return false;
    }
};