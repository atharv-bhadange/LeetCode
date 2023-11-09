class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        long long ans = 0;
        long long cnt = 1;
        int i = 1;
        while(i<s.size()) {
            if(s[i] == s[i-1])
            {
                cnt++;
            }
            else {
                ans += (cnt*(cnt+1))%MOD/2 % MOD;
                cnt = 1;
            }
            i++;
        }
        ans += (cnt*(cnt+1))%MOD/2 % MOD;
        return ans % MOD;
    }
};