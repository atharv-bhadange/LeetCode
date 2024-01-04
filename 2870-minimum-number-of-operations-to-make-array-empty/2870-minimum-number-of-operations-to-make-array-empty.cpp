class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& x: nums)
            mp[x]++;
        
        int ans = 0;
        
        for(auto [_, f]: mp) {
            if(f == 1)
                return -1;
            ans += ceil((float)f/3);
        }
        
        return ans;
    }
};