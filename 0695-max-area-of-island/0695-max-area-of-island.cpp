class Solution {
public:
    int area(vector<vector<int>>& grid, int i, int j, int& n ,int& m) {
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j] != 1) 
            return 0;
        
        int res = 1;
        grid[i][j] = '0';
        
        res += area(grid, i+1, j, n, m);
        res += area(grid, i-1, j, n, m);
        res += area(grid, i, j-1, n, m);
        res += area(grid, i, j+1, n, m);
        // cout<<res<<endl;
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int x = area(grid,i,j,n,m);
                    ans = max(ans, x);
                }
            }
        }
        
        return ans;
    }
};