class Solution {
public:
   
    int solve(vector<int>& nums, int n, vector<vector<int>>& dp, int last) {
        if(n<0) {
            return 0;
        }
        if(dp[n][last] != -1) {
            
        }
        int res = INT_MAX;
        
        if(nums[n] == last) {
            res = solve(nums, n-1, dp, last);
        }
        else {
            if(nums[n] < last) 
                res = min(res, solve(nums, n-1, dp, nums[n]));
            res = min(res, 1+solve(nums, n-1, dp, last));
        }
        
        return dp[n][last] = res;
    }
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1, vector<int>(4, -1));
        return solve(nums, n-1, dp, 3);
    }
};