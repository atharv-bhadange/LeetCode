class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        
        pre[0] = nums[0];
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            int curr = 0;
            if(i!=0) {
                curr += (nums[i]*i - pre[i-1]);
            }
            
            curr += (pre[n-1] - nums[i]*(n-i-1));
            
            curr -= pre[i];
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};