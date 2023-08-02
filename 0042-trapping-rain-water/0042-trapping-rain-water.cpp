class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> mxl(n),mxr(n);
        mxl[0] = arr[0];
        
        for(int i=1; i<n; i++) {
            mxl[i] = max(mxl[i-1], arr[i]);
        }
        
        mxr[n-1] = arr[n-1];
        
        for(int i=n-2; i>=0; i--) {
            mxr[i] = max(mxr[i+1], arr[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += min(mxr[i], mxl[i]) - arr[i];
        }
        
        return ans;
    }
};