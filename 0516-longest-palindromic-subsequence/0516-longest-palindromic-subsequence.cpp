class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs = "";
        int n = s.size();
        for(int i=n-1; i>=0; i--)
            rs += s[i];
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == rs[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int ans = 0; 
        for(int i=0; i<=n; i++) 
            for(int j=0; j<=n; j++)
                ans = max(dp[i][j], ans);
        return dp[n][n];
    }
};