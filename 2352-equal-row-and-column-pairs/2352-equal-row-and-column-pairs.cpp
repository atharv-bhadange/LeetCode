class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        map<vector<int>, int> m;
        for(int i=0; i<n; i++) {
            m[grid[i]]++;
        }
        
        for(int j=0; j<n; j++) {
            vector<int> col;
            for(int i=0; i<n; i++) {
                col.push_back(grid[i][j]);
            }
            ans += m[col];
        }
        
        return ans;
    }
};