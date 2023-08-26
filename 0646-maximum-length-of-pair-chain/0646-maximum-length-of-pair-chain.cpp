class Solution {
public:
    
    int solve(int idx, int& n, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if(idx == n)
            return 0;
        
        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
        
        int pick = 0;
        if(prev == -1 || pairs[prev][1] < pairs[idx][0]) 
            pick = 1+solve(idx+1, n, idx, pairs, dp);
        
        int notPick = solve(idx+1, n, prev, pairs, dp);
        
        return dp[idx][prev+1] = max(pick, notPick);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return solve(0, n, -1, pairs, dp);
    }
};