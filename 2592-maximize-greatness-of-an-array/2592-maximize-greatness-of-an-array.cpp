class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int idx = 0;
        for(int i=0; i<n; i++) {
            auto it = upper_bound(nums.begin()+idx+1, nums.end(), nums[i]);
            if(it != nums.end()) {
                ans++;
                idx=it-nums.begin();
            }
        }
        
        return ans;
    }
};