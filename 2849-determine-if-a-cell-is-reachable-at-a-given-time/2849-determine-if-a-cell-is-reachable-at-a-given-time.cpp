class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1)
            return 0;
        
        int mx = max(abs(sx-fx), abs(sy-fy));
        
        return mx <= t;
    }
};