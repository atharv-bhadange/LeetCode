class Solution {
public:
    
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int idx = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        if(idx != intervals.size())
            intervals.insert(intervals.begin() + idx, newInterval);
        else
            intervals.push_back(newInterval);
    }
    
    bool doesIntervalOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }
    
    vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        insertInterval(intervals, newInterval);
        
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++) {
            vector<int> currentInterval = intervals[i];
            
            while(i < intervals.size() && doesIntervalOverlap(currentInterval, intervals[i])) {
                currentInterval = mergeIntervals(currentInterval, intervals[i]);
                i++;
            }
            
            i--;
            ans.push_back(currentInterval);
        }
        
        return ans;
    }
};