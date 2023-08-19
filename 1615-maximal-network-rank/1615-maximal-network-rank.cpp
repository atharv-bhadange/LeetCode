class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        for(auto& x: roads) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    int c = graph[i].size() + graph[j].size();
                    auto it = find(graph[i].begin(), graph[i].end(), j);
                    if(it != graph[i].end())
                        c--;
                    ans = max(ans, c);
                }
            }
        }
        
        return ans;
    }
};