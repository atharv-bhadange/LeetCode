class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int f = 0, b = 0;
        while(f<nums.size()) {
            if(nums[f] - nums[b] > 2*k)
                b++;
            else 
                ans = max(ans, f-b+1);
            f++;
        }
        
        return ans;
    }
};