class Solution {
public:
    int recur(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        int n = mat.size();
        if(i>=n) {
            return 0;
        }
        if(dp[i][j] != -1) 
            return dp[i][j];

        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
        int cur = mat[i][j];
        // cout<<cur<<"cur";
        if(j-1>=0) {
            ans1 = cur + recur(mat,i+1,j-1, dp);
        }
        if(j+1<n) {
            ans2 = cur + recur(mat,i+1,j+1, dp);
        }
        ans3 = cur + recur(mat,i+1,j, dp);
        int ans = min(ans1, min(ans2, ans3));
        // cout<<ans<<"ans"<<endl;
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int i=0; i<matrix.size(); i++) {
            ans = min(ans, recur(matrix,0,i, dp));
        }

        return ans;
    }
};