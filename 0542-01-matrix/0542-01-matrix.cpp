class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    
    bool check(int i, int j) {
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    
    void solve(vector<vector<int>>& mat, vector<vector<int>>& ans) {
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()) {
            auto curr = q.front();
            q.pop();
            
            for(auto& d: dir) {
                int x = d[0] + curr.first;
                int y = d[1] + curr.second;
                
                if(check(x,y) && ans[x][y] == -1) {
                    q.push({x,y});
                    ans[x][y] = ans[curr.first][curr.second]+1;
                }
            }
        }
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,-1));
        solve(mat, ans);
        return ans;
    }
};