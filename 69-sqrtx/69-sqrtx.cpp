class Solution {
public:
    int mySqrt(int x) {
        if(x==0) 
            return 0;
        long long l = 1;
        long long r = INT_MAX;
        while(true) {
            int mid = (l+r)/2;
            if(mid > x/mid) r = mid-1;
            else {
                if((mid+1) > x/(mid+1))
                    return mid;
                else
                    l = mid + 1;
            }
        }
        
        return -1;
    }
};