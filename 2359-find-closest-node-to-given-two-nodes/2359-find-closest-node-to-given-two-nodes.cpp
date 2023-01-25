class Solution {
public:
    void dfs(int i, vector<int>& edges, vector<int>& dist, int cnt) {
        while(i != -1 && dist[i] == -1) {
            dist[i] = cnt++;
            i = edges[i];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> n1(n, -1), n2(n, -1);
        
        dfs(node1, edges, n1, 0);
        dfs(node2, edges, n2, 0);
        int res = -1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++) {
            if(n1[i] >=0 && n2[i] >= 0 && max(n1[i], n2[i]) < mini) {
                res = i;
                mini = max(n1[i], n2[i]);
            }
        }
        
        return res;
    }
};