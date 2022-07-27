class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        vector<vector<int>> b(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                b[i][j] = grid[j][i];
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            // vector<int> temp = grid[i];
            for (int k = 0; k < grid.size(); k++)
            {
                int cnt = 0;

                for (int j = 0; j < grid[0].size(); j++)
                {
                    // cout<<b[i][j]<<" ";
                    if (b[i][j] == grid[k][j])
                    {
                        cnt++;
                    }
                }
                // cout<<endl;
                if (cnt == grid.size())
                    ans++;
            }
            // cout<<endl;
            // if(cnt==grid.size())
            //     ans++;
        }

        return ans;
    }
};