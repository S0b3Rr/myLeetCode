class Solution {
public:
    int NumOfOne(int num){    
        int cnt = 0;
        while(num > 0){  
            if(num % 2 != 0) 
                cnt++; 
            num /= 2;  
        }
        return cnt;
    }

    
    vector<int> sortByBits(vector<int>& arr) {    
        multiset<pair<int, int>> s;
        for(int i = 0; i < arr.size(); i++){
            int ones = NumOfOne(arr[i]);
            s.insert({ones, arr[i]});
        }
        
        vector<int> ans;
        for(auto& it : s){
            ans.push_back(it.second);
        }
        return ans;
    }
};