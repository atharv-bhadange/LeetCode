class Solution
{
public:
    vector<vector<int>> v = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}}; // assign numbers to letters
    int MOD = 1e9 + 7;
    int recur(int n, int i, vector<vector<int>> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[n][i] != -1)
            return dp[n][i];

        dp[n][i] = 0;
        for (auto &x : v[i]) // call according to condition
            dp[n][i] = (dp[n][i] + recur(n - 1, x, dp)) % MOD;

        return dp[n][i];
    }

    int countVowelPermutation(int n)
    {

        vector<vector<int>> dp(n + 1, vector<int>(5, -1));

        int ans = 0;
        for (int i = 0; i < 5; i++) // string starting from all 5 letters
            ans = (ans + recur(n, i, dp)) % MOD;

        return ans;
    }
};

// tried similar appraoch with characters but got memory limit exceeded