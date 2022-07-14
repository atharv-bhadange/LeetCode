class Solution
{
public:
    int recur(int idx, vector<int> &cost, int n, vector<int> &dp)
    {

        if (idx >= n) // base case
            return 0;
        // cout<<idx<<endl;
        if (dp[idx] != -1)
            return dp[idx];
        int n1 = cost[idx] + recur(idx + 1, cost, n, dp); // 1st choice
        int n2 = cost[idx] + recur(idx + 2, cost, n, dp); // 2nd choice
        return dp[idx] = min(n1, n2);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);
        int n1 = recur(0, cost, n, dp);
        int n2 = recur(1, cost, n, dp);

        return min(n1, n2);
    }
};

// simple 1D dp... 