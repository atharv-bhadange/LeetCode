class Solution {
public:
    
    // vector<bool> vis;
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i==n) return j;
        int nextCol = j + grid[i][j];
        if(nextCol<0 || nextCol>= m || grid[i][j]!=grid[i][nextCol]) {
            return -1;
        }
        else
            return dfs(i+1, nextCol, n,m, grid); 
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        
        for(int i=0; i<grid[0].size(); i++)
            ans[i] = dfs(0,i,grid.size(), grid[0].size(), grid);
        
        return ans;
    }
};