class Solution {
public:
    
    bool check(int i,int j, int n, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        return (i>=0 && j>=0 && i<n && j<n && grid[i][j]==0 && !vis[i][j]);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        int ans=0;
        if(grid[0][0]!=1)
        {
            q.push({0,0});
            vis[0][0]=1;
        }
        
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            for(int i=0; i<size; i++)
            {
                auto f = q.front();
                q.pop();
                
                int l = f.first; int k = f.second;
                
                if(l==n-1 && k==n-1)
                    return ans;
                
                for(int i=l-1; i<=l+1; i++)
                    for(int j=k-1; j<=k+1; j++)
                    {
                        if(check(i,j,n,vis,grid))
                        {
                            q.push({i,j});
                            vis[i][j]=1;
                        }
                    }
                
                
            }
        }
        
        return -1;
    }
};

// bfs approach used to find shortest path
// dfs was not used as it was creating a lot of stack frames
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
