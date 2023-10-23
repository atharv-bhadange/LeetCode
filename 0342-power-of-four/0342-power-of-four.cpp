class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        
        long long x = log(n) / log(4);
        // cout<<x<<" "<<pow(4,x)<<endl;
        if(n==pow(4,x)){
            return true;
        }
        return false;
    }
};