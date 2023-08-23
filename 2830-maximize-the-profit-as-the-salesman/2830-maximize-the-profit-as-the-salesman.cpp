class Solution {
public:
    int solve(int idx, vector<vector<int>>& offers, vector<int>& dp) {
        if(idx == offers.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int notTaken = solve(idx+1, offers, dp);
        
        int l = idx+1, r = offers.size()-1;
        int new_nxt = offers.size();
        
        while(l<=r) {
            int mid = (r+l)/2;
            
            if(offers[mid][0] > offers[idx][1]) {
                r = mid-1;
                new_nxt = mid;
            }
            else 
                l = mid+1;
        }
        
        int taken = offers[idx][2] + solve(new_nxt, offers, dp);
        
        
        return dp[idx] = max(taken, notTaken);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end());
        vector<int> dp(m+1, -1);
        
        return solve(0, offers, dp);
    }
};