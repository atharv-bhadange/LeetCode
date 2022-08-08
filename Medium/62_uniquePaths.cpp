class Solution
{
public:
    int count = 0;
    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp) // my approach
    {
        if (i == m - 1 && j == n - 1)
        {
            // count++;
            return 1;
        }
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        ans += dfs(i + 1, j, m, n, dp);
        ans += dfs(i, j + 1, m, n, dp);

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m, vector<int> (n,-1));

        // cout<<dfs(0,0,m,n,dp)<<"\n";
        // cout<<count<<endl;
        vector<int> cur(n, 1); //simplest top-down approach
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
        // return dfs(0,0,m,n,dp);
    }
};