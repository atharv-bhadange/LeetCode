class Solution
{
public:
    int mx = 0;
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        int up = dfs(grid, i, j - 1);
        int down = dfs(grid, i, j + 1);
        int left = dfs(grid, i - 1, j);
        int right = dfs(grid, i + 1, j);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    mx = max(mx, dfs(grid, i, j));
                }
            }
        }

        return mx;
    }
};