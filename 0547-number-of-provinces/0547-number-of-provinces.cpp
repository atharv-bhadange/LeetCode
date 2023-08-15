class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int ver, vector<bool>& vis) {
        vis[ver] = 1;
        
        for(auto& child: graph[ver]) {
            if(!vis[child]) 
                dfs(graph, child, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j])
                    graph[i].push_back(j);
            }
        }
        
        vector<bool> vis(n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]){
                dfs(graph, i, vis);
                ans++;
            }
        }
        
        return ans;
        
    }
};