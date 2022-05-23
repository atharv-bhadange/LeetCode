class Solution
{
public:
    bool check(int n, int m, int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (!check(n, m, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

        if (check(n, m, i + 1, j) && matrix[i + 1][j] > matrix[i][j])
            c1 = dfs(matrix, dp, i + 1, j);

        if (check(n, m, i, j + 1) && matrix[i][j + 1] > matrix[i][j])
            c2 = dfs(matrix, dp, i, j + 1);

        if (check(n, m, i - 1, j) && matrix[i - 1][j] > matrix[i][j])
            c3 = dfs(matrix, dp, i - 1, j);

        if (check(n, m, i, j - 1) && matrix[i][j - 1] > matrix[i][j])
            c4 = dfs(matrix, dp, i, j - 1);

        dp[i][j] = 1 + max(c1, max(c2, max(c3, c4)));

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] == -1)
                {
                    ans = max(ans, dfs(matrix, dp, i, j));
                }
            }
        }

        return ans;
    }
};

// This is a DFS solution optimized by using dp matrix
