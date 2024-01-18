class Solution {
public:
    int fib(int n){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return fib(n-1)+fib(n-2);
    }
    int climbStairs(int n) {
        if(n==0 || n==1) return n;
        n++;
        int x = 1;
        int y = 0;
        int ans = 0;
        
        for(int i=2; i<=n; i++){
            int cur = x+y;
            y = x;
            x = cur;
            ans = cur;
        }
        
        return ans;
    }
};