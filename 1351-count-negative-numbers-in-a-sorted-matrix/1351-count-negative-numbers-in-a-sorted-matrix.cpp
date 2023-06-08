class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int ans = 0;
        for(int i=0; i<m; i++) {
            int l=0, r=n-1;
            int mid = 0;
            while(l<=r) {
                mid = (l+r)/2;
                if(grid[i][mid] >= 0)
                    l=mid+1;
                else 
                    r=mid-1;
                // cout<<grid[i][mid]<<" ";
            }
                cnt = n - l;
                ans += cnt;
        }
        
        return ans;
    }
};