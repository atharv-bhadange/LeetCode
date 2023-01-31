class Solution {
public:
    int recur(vector<pair<int,int>> &vp, vector<vector<int>>& dp, int n, int prev) {
        // base
        if(n>=vp.size())
            return 0;
        if(dp[prev+1][n] != -1)
            return dp[prev+1][n];
        
        if(prev == -1 || vp[n].second >= vp[prev].second) 
            dp[prev+1][n] = max(recur(vp, dp, n+1, prev), vp[n].second + recur(vp, dp, n+1, n)); 
        else 
            dp[prev+1][n] = recur(vp, dp, n+1, prev);
        
        return dp[prev+1][n];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vp;
        int n = scores.size();
        for(int i=0; i<n; i++) {
            vp.push_back({ages[i], scores[i]});
        }
        sort(vp.begin(), vp.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return recur(vp, dp, 0, -1);
    }
};