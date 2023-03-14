class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algo
        int ans = INT_MIN;
        int maxTillHere = 0;
        for(int i=0; i<nums.size(); i++) {
            maxTillHere += nums[i];
            if(maxTillHere > ans)
                ans = maxTillHere;
            if(maxTillHere<0)
                maxTillHere = 0;
        }
        
        return ans;
    }
};