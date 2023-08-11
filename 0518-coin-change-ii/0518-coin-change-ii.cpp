class Solution {
public:
    
    int coinChange2(vector<int> &coins, vector<vector<int>> &dp, int n, int sum)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (coins[n - 1] <= sum)
        {
            dp[n][sum] = coinChange2(coins, dp, n, sum - coins[n - 1]) + coinChange2(coins, dp, n - 1, sum);
        }
        else
            dp[n][sum] = coinChange2(coins, dp, n - 1, sum);

        return dp[n][sum];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return coinChange2(coins, dp, n, amount);
    }
};