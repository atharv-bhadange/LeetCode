class Solution {
public:
    int recur(vector<int>& arr, int k, int start, vector<int>& dp) {
        int n = arr.size();
        
        if(start >= n)
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        int curr = 0, ans = 0;
        
        int end = min(n, start + k);
        
        for(int i=start; i<end; i++) {
            curr = max(arr[i], curr);
            
            ans = max(ans, curr * (i - start + 1) + recur(arr, k, i + 1, dp));
        }
        
        return dp[start] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        
        return recur(arr, k, 0, dp);
    }
};