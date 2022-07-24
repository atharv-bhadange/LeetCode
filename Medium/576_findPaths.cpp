class Solution
{
public:
    int MOD = 1e9 + 7;
    int dp[55][55][55];
    int recur(int i, int j, int m, int n, int moves)
    {
        if (i < 0 || j < 0 || i == m || j == n)
            return 1;
        if (moves == 0)
            return 0;
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];

        dp[i][j][moves] = ((recur(i + 1, j, m, n, moves - 1) + recur(i - 1, j, m, n, moves - 1)) % MOD + (recur(i, j + 1, m, n, moves - 1) + recur(i, j - 1, m, n, moves - 1)) % MOD) % MOD;

        return dp[i][j][moves];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return recur(startRow, startColumn, m, n, maxMove);
    }
};