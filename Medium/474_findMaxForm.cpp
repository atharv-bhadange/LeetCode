class Solution
{
public:
    int dp[601][101][101];
    pair<int, int> countNums(string &l)
    {
        int z = 0;
        int o = 0;
        for (int i = 0; i < l.size(); i++)
        {
            if (l[i] == '1')
                o++;
            else
                z++;
        }

        return {o, z};
    }

    int solve(int i, int ones, int zeros, int &m, int &n, vector<string> &s)
    {
        if (i >= s.size())
            return 0;

        if (ones > n || zeros > m)
            return 0;

        if (dp[i][zeros][ones] != -1)
            return dp[i][zeros][ones];

        pair<int, int> p = countNums(s[i]);

        int ans1 = 0, ans2 = 0, withoutAns = 0;

        if (p.second + zeros <= m & p.first + ones <= n)
        {
            ans1 = 1 + solve(i + 1, p.first + ones, p.second + zeros, m, n, s);

            ans2 = solve(i + 1, ones, zeros, m, n, s);
        }
        else
            withoutAns = solve(i + 1, ones, zeros, m, n, s);

        return dp[i][zeros][ones] = max(ans1, max(ans2, withoutAns));
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, m, n, strs);
    }
};

// use of 3D dp array in this problem
// would consider to put this question in hard

// recursive we decide if to take a particular string or not
// if the counts does exceed the limits then we don't take it
// als0 if it doesnt exceed the limits then we have two choices
// take it or leave it
// we return the max of these three choices
