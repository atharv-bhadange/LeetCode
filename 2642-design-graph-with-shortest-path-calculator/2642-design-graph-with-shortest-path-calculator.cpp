class Graph {
public:
    vector<vector<pair<int,int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        
        for(auto& edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = graph.size();
        vector<int> cost(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, node1});
        cost[node1] = 0;
        
        while(!pq.empty()) {
            int currCost = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            
            if(currCost > cost[node]) {
                continue;
            }
            
            if(node == node2) {
                return currCost;
            }
            
            for(auto& n : graph[node]) {
                int nNode = n.first;
                int nCost = n.second;
                
                int newCost = nCost + currCost;
                
                if(newCost < cost[nNode]) {
                    cost[nNode] = newCost;
                    pq.push({newCost, nNode});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */