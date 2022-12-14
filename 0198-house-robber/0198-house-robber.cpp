class Solution {
public:
    int recur(vector<int>& nums, int n, vector<int>& dp) {
        if(n<=0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ignore, broke;
        ignore = recur(nums, n-1, dp);
        broke = nums[n-1] + recur(nums, n-2, dp);

        return dp[n] = max(ignore, broke);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return recur(nums, nums.size(), dp);
    }
};