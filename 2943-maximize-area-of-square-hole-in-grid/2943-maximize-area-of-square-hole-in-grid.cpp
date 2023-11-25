class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       sort(hBars.begin(), hBars.end());
       sort(vBars.begin(), vBars.end());
        
        int prev = -1;
        int mx1 = 1, mx2 = 1;
        int cnt = 1;
        for(auto& x : hBars) {
    
            if(x == prev+1) {
                cnt++;
                mx1 = max(mx1, cnt);
            } else {
                cnt = 1;
            }
            
            prev = x;
        }
        prev = -1;
        cnt = 1;
        for(auto& x : vBars) {
    
            if(x == prev+1) {
                cnt++;
                mx2 = max(mx2, cnt);
            } else {
                cnt = 1;
            }
            
            prev = x;
        }
        
        int ans = min(mx1, mx2)+1;
        return ans*ans;
    }
};