class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> graph(n);
        for(auto& path: flights) {
            graph[path[0]].push_back({path[1], path[2]});
        }
        queue<pair<int,int>> q;
        q.push({src, 0});
        int stops = 0;
        while(!q.empty() && stops<=k) {
            int size = q.size();
            while(size--) { 
                auto [node, wt] = q.front();
                q.pop();
                for(auto& [nigga, price] : graph[node]) {
                    if(price + wt < dist[nigga]) {
                        dist[nigga] = price + wt;
                        q.push({nigga, dist[nigga]});
                    }
                }
            }
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};