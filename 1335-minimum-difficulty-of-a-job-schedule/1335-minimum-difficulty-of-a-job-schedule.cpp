class Solution {
public:
    int recur(int d, int l, vector<int>& jd, vector<vector<int>>& dp) {
        int n = jd.size();
        if(d==0 && l==n) return 0;
        if(d==0 || l==n) return INT_MAX;
        
        if(dp[l][d]!=-1) return dp[l][d];
        
        int curMax = jd[l];
        int mini = INT_MAX;
        
        for(int i=l; i<n; i++) {
            curMax = max(curMax, jd[i]);
            int temp = recur(d-1,i+1,jd,dp);
            if(temp!=INT_MAX) 
                mini = min(mini, temp+curMax);
        }
        
        return dp[l][d] = mini;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n<d) return -1;
        
        vector<vector<int>> dp(n, vector<int>(d+1,-1));
        
        return recur(d, 0, jd, dp);
    }
};