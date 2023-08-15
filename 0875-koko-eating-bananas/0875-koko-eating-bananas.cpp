class Solution {
public:
    
    long eat(vector<int>& piles, int cnt) {
        long hrs = 0;
        for(auto x: piles) {
            hrs += (x/cnt);
            if(x%cnt != 0)
                hrs++;
        }
        
        return hrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        while(l<r) {
            int mid = l + (r-l)/2;
            
            if(eat(piles, mid) <= h) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        
        return l;
    }
};