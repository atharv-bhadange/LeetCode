class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> pre(n+1), suf(n+1);
        
        for(int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + (customers[i-1] == 'N');
        }
        
        for(int i=n-1; i>=0; i--) {
            suf[i] = suf[i+1] + (customers[i] == 'Y');
        }
        
        int ans = 0;
        int mini = INT_MAX;
        for(int i=0; i<=n; i++) {
            if(mini > suf[i]+pre[i]) {
                mini = suf[i] + pre[i];
                ans = i;
            }
        }
        
        return ans;
    }
};