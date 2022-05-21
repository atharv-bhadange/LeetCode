class Solution {
public:
    int compute(vector<int>& coins, int amount, int n, vector<vector<int>>& dp)
    {
        if(amount==0) return 0;
        if(n<0 || amount<0) return INT_MAX-1;
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int f = compute(coins, amount, n-1, dp);
        int s = 1+compute(coins, amount-coins[n], n, dp);
        
        dp[n][amount] = min(f,s);
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1, -1));
        int ans = compute(coins, amount, coins.size()-1, dp);
        return ans==INT_MAX-1 ? -1 : ans;
    }
};

//standard dp problem