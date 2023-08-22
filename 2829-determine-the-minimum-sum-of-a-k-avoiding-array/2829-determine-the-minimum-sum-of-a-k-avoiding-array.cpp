class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> m;
        int ans = 0;
        int i = 1;
        for(; i<=n && i<=k/2; i++) {
            m[i] = 1;
            ans += i;
        }
        
        if(m.size() != n) {
            int cnt = i;
            while(cnt<=n) {
                // cout<<i<<" ";
                if(m[k-i] == 1) {
                    i++;
                    continue;
                }
                ans += i;
                i++;
                cnt++;
            }
        }
        
        return ans;
    }
};