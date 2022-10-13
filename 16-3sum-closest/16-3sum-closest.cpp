class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            int j = i+1, k = n-1;
            while(j<k) {
                int curr = nums[i]+nums[j]+nums[k];
                if(abs(curr-target) < abs(ans-target)) {
                    ans = curr;
                    
                }
                if(curr<target) {
                    j++;
                }
                else if(curr>target) {
                    k--;
                }
                else return target;
            }
        }
        
        return ans;
    }
};