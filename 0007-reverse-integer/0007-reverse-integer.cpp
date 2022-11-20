class Solution {
public:
    long long reve(int k) {
        long long res = 0;
        while(k) {
            int l = k%10;
            res = res*10 + l;
            k/=10;
        }
        return res;
    }
    
    int reverse(int x) {
        long long k = x;
        if(k<0) k = abs(k);
        long long f = reve(k);
        if(x<0)
            f = -1*f;
        if(f>INT_MAX|| f<INT_MIN) f=0;
        
        return f;
    }
};