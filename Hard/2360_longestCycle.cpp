class Solution
{
public:
    int ans = -1;
    void dfs(vector<int> &edges, int idx, vector<bool> &vis, vector<int> &store)
    {
        if (idx == -1)
            return;

        if (vis[idx])
        {
            int cnt = -1;
            for (int i = 0; i < store.size(); i++)
            {
                if (store[i] == idx)
                {
                    cnt = i;
                    break;
                }
            }

            if (cnt == -1)
                return;
            int len = store.size() - cnt;
            ans = max(ans, len);
            return;
        }

        vis[idx] = true;
        store.push_back(idx);
        dfs(edges, edges[idx], vis, store);
    }

    int longestCycle(vector<int> &edges)
    {
        vector<bool> vis(edges.size() + 1, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            if (vis[i])
                continue;
            vector<int> store;
            dfs(edges, i, vis, store);
        }
        return ans;
    }
};

// call dfs on all nodes, store every node's path in store vector
// when we encounter already visited node we check if that path forms a cycle and find the max length amongst all such cycles