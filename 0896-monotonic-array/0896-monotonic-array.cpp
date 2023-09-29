class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        bool f1 = false;
        for(int i=0; i<n-1; i++) {
            if(nums[i] < nums[i+1]) {
                f1 = true;
                break;
            }
        }
        if(!f1)
            return true;
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                f1 = false;
                break;
            }
        }
        
        if(f1)
            return true;
        return false;
    }
};