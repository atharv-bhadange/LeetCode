class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> vec(n + 1);

        for (int i = 0; i < times.size(); i++)
        {
            vec[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        queue<int> q;
        q.push(k);

        dist[k] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto p : vec[curr])
            {
                if (dist[p.first] > dist[curr] + p.second)
                {
                    dist[p.first] = dist[curr] + p.second;
                    q.push(p.first);
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {

            if (dist[i] == INT_MAX)
                return -1;

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};

// Above solution is by BFS
// Tried to apply Dijkstra alogrithm but found that is more difficult to implement for this question