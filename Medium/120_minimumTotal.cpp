class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &t, int m, vector<vector<int>> &dp)
    {
        int n = t[i].size();
        if (i == m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans1 = t[i][j] + solve(i + 1, j, t, m, dp);
        int ans2 = INT_MAX;
        if (j + 1 != m)
            ans2 = t[i][j] + solve(i + 1, j + 1, t, m, dp);

        return dp[i][j] = min(ans1, ans2);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        return solve(0, 0, triangle, m, dp);
    }
};

// first dp question self solved
