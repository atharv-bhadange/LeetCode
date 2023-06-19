class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int pre = 0;
        for(int i=0; i<n; i++) {
            pre += gain[i];
            ans = max(pre, ans);
        }
        
        return ans;
    }
};