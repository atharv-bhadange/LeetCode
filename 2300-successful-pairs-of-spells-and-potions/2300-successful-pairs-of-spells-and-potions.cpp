class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto& x: spells) {
            double y =  success / (double)x;
            auto it = lower_bound(potions.begin(), potions.end(), y);
            ans.push_back(potions.end() - it);
        }
        
        return ans;
        
    }
};