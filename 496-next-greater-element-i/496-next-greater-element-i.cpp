class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stackk;
        unordered_map<int, int> map;
        
        for (auto& n : nums2) {
            while (!stackk.empty() && stackk.top() < n) {
                map[stackk.top()] = n; //update the corresponding next greater element
                stackk.pop();
            }
            stackk.push(n);
        }
        
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            unordered_map<int, int>::iterator it = map.find(nums1[i]);
            if (it != map.end()) 
                ans[i] = it -> second;
        }
        return ans;
    }
};