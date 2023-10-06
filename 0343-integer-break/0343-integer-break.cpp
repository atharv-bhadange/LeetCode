class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)
            return n-1;
        int q = n/3;
        int rem = n%3;
        
        if(rem==0)
            return pow(3, q);
        if(rem==1)
            return pow(3, q-1)*4;
        
        return pow(3, q)*2;
    }
};