class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> pre(nums.size());
        sort(nums.begin(), nums.end());
        pre[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            int fd = queries[i];
            auto it = upper_bound(pre.begin(), pre.end(), fd);
            ans.push_back(it - pre.begin());
        }
        
        return ans;
    }
};