class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int curr = nums[i]+nums[j]+nums[k];
                if(curr<0) j++;
                else if(curr>0) k--;
                else {
                    st.insert({nums[i],nums[j],nums[k]});
                    j++,k--;
                }
            }
        }
        for(auto &x:st) 
            ans.push_back(x);
        
        return ans;
    }
};