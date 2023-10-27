class Solution {
public:
    bool recur(string& s, vector<vector<int>>& dp, int l, int r, vector<int>& ans)
    {
        //dp condition
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(l>=r)
            return true;
        
        bool found = false;
        if(s[l]==s[r])
        {
            found=true && recur(s,dp,l+1,r-1,ans);
        }
        
        recur(s,dp,l+1,r,ans);
        recur(s,dp,l,r-1,ans);
        
        if(found && r-l+1>ans[2])
            ans = {l,r,r-l+1};
        
        return dp[l][r] = found;
    }
    
    string longestPalindrome(string s) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        vector<int> ans = {0,0,1};
        recur(s,dp,0,s.size()-1,ans);
        
        return s.substr(ans[0],ans[2]);
    }
};