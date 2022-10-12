class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.rbegin(),a.rend());
        int ans = 0;
        for(int i=0; i<a.size()-2; i++) {
            if(a[i]>=a[i+1]+a[i+2]) continue;
            else
            {
                ans = a[i] + a[i+1] + a[i+2];
                break;
            }
        }
        return ans;
    }
};