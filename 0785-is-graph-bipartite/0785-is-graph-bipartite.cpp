class Solution {
public:
    bool validColor(vector<vector<int>>& graph, vector<int>& colors, int vertex, int color) {
        if(colors[vertex]) {
            return colors[vertex] == color;
        }
        
        colors[vertex] = color;
        
        for(int child: graph[vertex]) {
            if(!validColor(graph, colors, child, -1*color)){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        
        for(int i=0; i<n; i++) {
            if(!colors[i]) {
                if(!validColor(graph, colors, i, 1))
                    return false;
            }
        }
        
        return true;
    }
};