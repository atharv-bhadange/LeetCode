class Solution {
    
    int lcs(string s1, string s2, int n, int m, vector<vector<int>> &dp) // recursive solution
    {
        if(n==0 || m==0)
            return 0;

        if(dp[n][m]!=-1)
            return dp[n][m];

        int ans=0,ans1=0,ans2=0;
        if(s1[n-1] == s2[m-1])
            ans = 1+lcs(s1,s2,n-1,m-1, dp);
        else
        {
            ans2 = lcs(s1,s2,n-1,m, dp);
            ans1 = lcs(s1,s2,n,m-1, dp);
        }

        return dp[n][m] = max(ans,max(ans1,ans2));
    }
    
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        // int l = lcs(s1,s2,n,m,dp);
        for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
        for (int j = 0; j < m + 1; j++)
            dp[0][j] = 0;

        for (int i = 1; i < n + 1; i++) // iterative solution
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int l = dp[n][m];

        int ans = n-l + m-l;
        
        return ans;
    }
};