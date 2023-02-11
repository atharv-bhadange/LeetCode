class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        // set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int curr = nums[i]+nums[j]+nums[k];
                if(curr<0) j++;
                else if(curr>0) k--;
                else {
                    vector<int> currT = {nums[i],nums[j],nums[k]};
                    ans.push_back(currT);
                    while(j<k && nums[j]==currT[1]) j++;
                    while(j<k && nums[k]==currT[2]) k--;
                }
                while(i+1 < n && nums[i] == nums[i+1]) i++;
            }
        }
        // for(auto &x:st) 
            // ans.push_back(x);
        
        return ans;
    }
};