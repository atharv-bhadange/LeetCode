class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));

        int start = 0;
        int end = 0;
        for (int len = 0; len < n; len++)
        {
            for (int i = 0; i + len < n; i++)
            {
                dp[i][i + len] = (s[i] == s[i + len]) && (len < 2 || dp[i + 1][i + len - 1]);
                if (dp[i][i + len] && len > end - start)
                {
                    start = i;
                    end = i + len;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};