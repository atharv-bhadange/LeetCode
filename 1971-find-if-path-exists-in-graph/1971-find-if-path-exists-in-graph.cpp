class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int ver, int d){
        vis[ver] = true;
        
        if(ver==d){
            return true;
        }
        
        bool ans = false;
        for(auto &child : graph[ver])
        {
            if(!vis[child])
                ans |= dfs(graph,vis,child,d);
        }
        
        return ans;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // int n = edges.size();
        vector<vector<int>> graph(n);
        
        for(auto &x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n,0);
        return dfs(graph,vis,source,destination);
    }
};