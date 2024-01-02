class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        vector<vector<int>> ans;
        
        int s = mp.size();
        
        while(s>0) {
            vector<int> t;
            for(auto& x: mp) {
                if(x.second != 0) {
                    t.push_back(x.first);
                    x.second--;
                    if(x.second == 0) {
                        s--;
                    }
                }
            }
            ans.push_back(t);
        }
        
        return ans;
    }
};