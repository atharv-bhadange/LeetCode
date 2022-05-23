class Solution
{
    vector<vector<int>> ans;

public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &time, vector<int> &les, int &cnt, int vertex, int parent)
    {
        vis[vertex] = true;
        time[vertex] = les[vertex] = cnt++;

        for (auto &child : graph[vertex])
        {
            if (child == parent)
                continue;
            if (!vis[child])
            {
                dfs(graph, vis, time, les, cnt, child, vertex);
            }
            les[vertex] = min(les[vertex], les[child]);

            if (les[child] > time[vertex]) // if child is greater than parent, then it is a critical point
                ans.push_back({vertex, child});

            // {
            //     vector<int> temp;
            //     temp.push_back(child);
            //     temp.push_back(vertex);
            //     ans.push_back(temp);
            // }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<bool> vis(n, 0);
        vector<int> time(n, -1), les(n, -1);
        int timer = 0;
        vector<vector<int>> graph(n);
        for (auto &edge : connections)
        {
            int nodeA = edge[0], nodeB = edge[1];
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }

        dfs(graph, vis, time, les, timer, 0, -1);

        return ans;
    }
};

// Bridges in a graph concept is used
// In this we maintain 2 arrays:
//  1. low[i] : The lowest vertex reachable from vertex i
//  2. timer[i] : The time when vertex i was visited
