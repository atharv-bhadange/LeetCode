class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            if(currSum<0) {
                currSum = 0;
            }
            ans = max(ans,currSum);
        }
        if(ans==0) {
            ans = *max_element(nums.begin(),nums.end());
        }
        
        return ans;
    }
};