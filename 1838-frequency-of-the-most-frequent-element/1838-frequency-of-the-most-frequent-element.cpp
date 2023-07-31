class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans=1;
        long long sum = 0;
        while(j<n) {
            sum += nums[j];
            
            // long long ideal_sum = ;
            if(1LL*(j-i+1)*nums[j] - sum > k)
                while(1LL*(j-i+1)*nums[j] - sum > k)
                    sum -= nums[i++];
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};