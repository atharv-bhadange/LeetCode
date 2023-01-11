class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& hasApple) {
        int totalTime = 0;
        int childTime = 0;
        for(auto& child : graph[node]) {
            if(child != parent) {
                childTime = dfs(child, node, graph, hasApple);
                if(childTime || hasApple[child])
                    totalTime += childTime + 2;
            }
        }
        
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return dfs(0, -1, graph, hasApple);
    }
};