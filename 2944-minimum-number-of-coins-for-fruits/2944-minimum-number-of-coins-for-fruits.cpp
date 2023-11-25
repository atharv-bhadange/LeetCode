class Solution {
public:
    
    int solve(vector<int>& prices, int i, int free, vector<vector<int>>& dp) {
        if(i==prices.size()) {
            return 0;
        }
        
        if(dp[i][free] != -1)
            return dp[i][free];
        
        int cnt1 = INT_MAX, cnt2 = INT_MAX;
        if(free != 0) {
            cnt1 = solve(prices, i+1, free-1, dp);
            cnt2 = prices[i] + solve(prices, i+1, i+1, dp);
        } else {
            cnt2 = prices[i] + solve(prices, i+1, i+1, dp);
        }
        
        return dp[i][free] = min(cnt1, cnt2);
    }
    
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n+2, vector<int> (n+2, -1));
        return solve(prices, 0, 0, dp);
    }
};