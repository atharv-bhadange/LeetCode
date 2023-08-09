class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return 1;
        int l=2, r=num-1;
        long long mid;
        while(l<=r) {
            mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(mid*mid == num)
                return 1;
            else if(mid*mid > num)
                r=mid-1;
            else
                l=mid+1;
        }
        
        return 0;
    }
};