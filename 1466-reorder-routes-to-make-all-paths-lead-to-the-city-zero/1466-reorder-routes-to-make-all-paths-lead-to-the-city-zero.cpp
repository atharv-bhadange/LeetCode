class Solution {
public:
    int ans = 0;
    void dfs(int ver, int parent, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[ver] = 1;
        for(auto& child: graph[ver]) {
            if(!vis[abs(child)]) {
                ans += (child > 0);

                dfs(abs(child), ver, graph, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto& x: connections) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(-x[0]);
        }
        vector<bool> vis(n);
        
        dfs(0, -1, graph, vis);
        
        return ans;
    }
};