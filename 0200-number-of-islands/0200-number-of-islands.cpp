class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int& n, int& m) {
        if(i>=m || j>=n || j<0 || i<0 || grid[i][j] != '1') 
            return;
        
        grid[i][j] = '0';
        
        dfs(grid, i+1, j, n, m);
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i, j+1, n, m);
    } 
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(grid[i][j] != '1') {
                    continue;
                }
                ans++;
                dfs(grid, i, j, n, m);
            }
        
        return ans;
    }
};