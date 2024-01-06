class Solution {
public:
    int solve(int i, int n, vector<vector<int>>& jobs, vector<int>& start, vector<int>& dp) {
        if(i>=n) 
            return 0;
        
        if(dp[i] != 0) {
            return dp[i];
        }
        
        int idx = lower_bound(start.begin(), start.end(), jobs[i][1]) - start.begin();
        
        int pick = jobs[i][2] + solve(idx, n, jobs, start, dp);
        int leave = solve(i+1, n, jobs, start, dp);
        
        return dp[i] = max(pick, leave);
    }
        
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        vector<int> dp(n+1, 0);
        
        for(int i=0; i<n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        
        return solve(0, n, jobs, startTime, dp);
    }
};