class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<nums[i].size(); j++) {
                int sum = i+j;
                mp[sum].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        int cnt = 0;
        while(mp.find(cnt) != mp.end()) {
            for(auto& x: mp[cnt]) {
                ans.push_back(x);
            }
            cnt++;
        }
        
        return ans;
    }
};