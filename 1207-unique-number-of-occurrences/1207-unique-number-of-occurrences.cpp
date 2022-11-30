class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp, mpmp;
        for(auto& x : arr) {
            mp[x]++;
        }
        for(auto& x : mp) {
            mpmp[x.second]++;
        }
        for(auto& x : mpmp) {
            if(x.second!=1)
                return false;
        }
        
        return true;
    }
};