class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> onesRow(m);
        vector<int> onesCol(n);
        vector<int> zerosRow(m);
        vector<int> zerosCol(n);
        
        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++)
                if(grid[i][j]==1)
                    cnt++;
            onesRow[i] = cnt;
        }
        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++)
                if(grid[i][j]==0)
                    cnt++;
            zerosRow[i] = cnt;
        }
        
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<m; j++)
                if(grid[j][i]==1)
                    cnt++;
            onesCol[i] = cnt;
        }
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<m; j++)
                if(grid[j][i]==0)
                    cnt++;
            zerosCol[i] = cnt;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        
        return grid;
    }
};