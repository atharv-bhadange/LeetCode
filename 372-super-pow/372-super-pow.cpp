class Solution {
public:
    const int MOD = 1337;
//     long long convert(vector<int>& b) {
//         int n = b.size();
//         long long ans = 0;
//         for(int i=0; i<n; i++) {
//             ans = 10*ans + b[i];
//         }
        
//         return ans;
//     }
//     int myPow(long long a, long long b) {
//         return b%2==0 ? myPow(a*a,b/2)%MOD : (a%MOD*(myPow(a*a,b/2)%MOD))%MOD;
//     }
    
    int fmod(int a, int b) {
        a %= MOD;
        int res = 1;
        for(int i=0; i<b; i++)
            res = (res*a)%MOD;
        
        return res % MOD;
    }
    
    int superPow(int a, vector<int>& b) {
        // long long bc = convert(b);
        // a = a % MOD;
        // return myPow(1ll*a,bc)%MOD;
        
        if(b.empty()) return 1;
        int ld = b.back();
        b.pop_back();
        return fmod(superPow(a,b), 10) * fmod(a, ld) % MOD;
    }
};