class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n-1; i++) {
            if(nums[i] != nums[i+1]) {
                cnt++;
            }
            
            ans+=cnt;
        }
        
        return ans;
    }
};