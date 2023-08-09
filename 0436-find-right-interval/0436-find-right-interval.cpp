class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int i=0;
        for(auto& x: intervals)
            x.push_back(i),i++;
        sort(intervals.begin(), intervals.end());
        vector<int> ans(intervals.size());
        for(int i=0; i<intervals.size(); i++) {
            int key = intervals[i][1];
            int l=0, r=intervals.size()-1;
            int mid;
            while(l<r) {
                mid = l+(r-l)/2;
                if(intervals[mid][0] >= key) {
                    r=mid;
                }
                else
                    l=mid+1;
            }
            if(intervals[l][0] >= key)
                ans[intervals[i][2]] = intervals[l][2];
            else
                ans[intervals[i][2]] = -1;
        }
        
        return ans;
    }
};