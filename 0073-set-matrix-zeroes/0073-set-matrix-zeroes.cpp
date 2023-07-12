class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int n = ma.size();
        int m = ma[0].size();
        unordered_set<int> row;
        unordered_set<int> col;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ma[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto& r: row) {
            for(int j=0; j<m; j++) {
                ma[r][j] = 0;
            }
        }
        
        for(auto& c: col) {
            for(int i=0; i<n; i++) {
                ma[i][c] = 0;
            }
        }
    }
};