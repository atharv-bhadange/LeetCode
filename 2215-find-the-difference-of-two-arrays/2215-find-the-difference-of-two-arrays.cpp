class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums1, vector<int>& nums2, vector<int>& t, unordered_map<int,int>& m) {
        for(auto& x: nums1) 
            m[x]++;
        for(auto& x: nums2)
            m[x]=0;
        for(auto& x: m) {
            if(x.second)
                t.push_back(x.first);
        }
        ans.push_back(t);
        t.clear();
        m.clear();
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> t;
        unordered_map<int,int> m;
       
        solve(nums1,nums2,t,m);
        solve(nums2,nums1,t,m);
        
        return ans;
    }
};