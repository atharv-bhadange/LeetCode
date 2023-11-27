class Solution {
public:
    
    int MOD = 1e9+7;
    
    vector<vector<int>> canJump = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int solve(int moves, int square, vector<vector<int>>& dp) {
        if(moves == 0)
            return 1;
        
        if(dp[moves][square] != -1)
            return dp[moves][square];
        
        int ans = 0;
        
        for(auto& i: canJump[square]) {
            ans = (ans + solve(moves-1, i, dp))%MOD;
        }
        
        return dp[moves][square] = ans;
    }
    
    int knightDialer(int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(10, -1));
        int ans = 0;
        
        for(int i=0; i<10; i++) {
            ans = (ans + solve(n-1, i, dp))%MOD;
        }
        
        return ans;
    }
};