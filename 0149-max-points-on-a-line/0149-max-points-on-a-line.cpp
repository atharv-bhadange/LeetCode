class Solution {
public:
    double slope(int x1, int y1, int x2, int y2) {
        if(x1-x2 == 0)
            return INT_MAX;
        return (y2-y1)/double(x2-x1);
    }
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 2;
        int n = points.size();
        if( n==1 )
            return 1;
        for(int i=0; i<n; i++) {
            unordered_map<double,int> mp;
            for(int j=i+1; j<n; j++) {
                
                    double x = slope(points[i][0], points[i][1], points[j][0], points[j][1]);
                    mp[x]++;
                
            }
            for(auto& x : mp) 
                ans = max(ans, x.second+1);
        }
        return ans;
        // int temp = 0;
        // for(auto& x: mp) {
        //     cout<<x.first<<" "<<x.second<<endl;
        //     temp = max(temp, x.second);
        // }
        // int ans = (sqrt(1+8*temp) - 1)/2;
        // return ans+1;
    }
};