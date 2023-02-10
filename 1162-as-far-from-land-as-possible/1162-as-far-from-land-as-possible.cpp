class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int col = grid[0].size(), row = grid.size();
        int maxi = row + col + 1;
        vector<vector<int>> v(row, vector<int>(col, maxi));
        for(int i=0; i<row;  i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]){
                    v[i][j] = 0;
                }
                else{
                    int temp1=maxi,temp2=maxi;
                    if(i>0){
                        temp1 = v[i-1][j] + 1;
                    }
                    if(j>0){
                        temp2 = v[i][j-1] + 1;
                    }
                    v[i][j] = min(v[i][j], min(temp1,temp2));
                }
            }
        }
        int ans = INT_MIN;
        for(int i= row-1; i>=0; i--) {
            for(int j=col-1; j>=0; j--) {
                v[i][j] = min(v[i][j], min(i < row-1 ? v[i+1][j] + 1 : maxi , j < col-1 ? v[i][j+1] +1 : maxi));
                
                ans = max(ans, v[i][j]);
            }
        }
        
        return ans == 0 || ans == maxi ? -1 : ans;
    }
};