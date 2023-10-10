class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1])
            return a[0] < b[0];
        
        return a[1] < b[1];
    }
    int hardestWorker(int n, vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end(), cmp);
        
        int mx = 0;
        int ans = 0;
        int prev = 0;
        for(int i=0; i<logs.size(); i++) {

            if(mx < logs[i][1] - prev || (logs[i][1] - prev==mx && ans > logs[i][0])) {
                mx = logs[i][1] - prev;
                ans = logs[i][0];
            }
            prev = logs[i][1];
        }
        
        return ans;
    }
};

