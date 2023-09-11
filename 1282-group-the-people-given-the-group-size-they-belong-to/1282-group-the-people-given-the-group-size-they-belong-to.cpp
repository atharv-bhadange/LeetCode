class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> vp;
        vector<vector<int> >ans;
        
        for(int i=0; i<groupSizes.size(); i++) {
            vp.push_back({groupSizes[i], i});
        }
        sort(vp.begin(), vp.end());

        int i=0;
        int n = vp.size();
        while(i<n) {
            vector<int> t;
            int curr_size = vp[i].first;
            while(i < n && t.size() != curr_size) {
                t.push_back(vp[i].second);
                i++;
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};