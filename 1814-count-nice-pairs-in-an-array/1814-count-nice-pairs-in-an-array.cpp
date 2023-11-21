class Solution {
public:
    int MOD = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());
            int num = stoi(str);
            
            ans = (ans + mp[nums[i]-num])%MOD;
            mp[nums[i]-num]++;
        }
        
        return ans;
    }
};