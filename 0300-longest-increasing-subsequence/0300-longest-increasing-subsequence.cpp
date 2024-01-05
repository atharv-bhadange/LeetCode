class Solution {
public:
    int recur(vector<int>& nums, int last, int n, vector<int>& dp)
    {
        if(n==0)
            return 0;
        if(dp[last+1]!=-1)
            return dp[last+1];
        int ans = 0;
        int ans2 = recur(nums,last,n-1,dp); 
        if(last ==-1 || nums[n-1]<nums[last])
        {
            ans = 1+recur(nums,n-1,n-1,dp);
        }
        
        return dp[last+1] = max(ans,ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return recur(nums,-1,nums.size(),dp);
    }
};