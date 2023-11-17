class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0, j=n-1; j>=0 && i<n; i++, j--) {
            int sum = nums[i] + nums[j];
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};