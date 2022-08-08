class Solution {
public:
    void dfs(int i, int cnt, vector<int>& edges, vector<int>& dist) {
        while(i!= -1 && dist[i]==-1) 
        {
            dist[i] = cnt++; //count distance from all reachable nodes and store it in vector
            i = edges[i];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> n1(n,-1), n2(n,-1);
        dfs(node1, 0, edges, n1);
        dfs(node2, 0, edges, n2);
        
        int res = -1;
        int minD = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            if(n1[i]>=0 and n2[i]>=0 and max(n1[i],n2[i]) < minD) // minimize the max of both distances
            {
                minD = max(n1[i],n2[i]);
                res = i;
            }
        }
        
        return res;
    }
};