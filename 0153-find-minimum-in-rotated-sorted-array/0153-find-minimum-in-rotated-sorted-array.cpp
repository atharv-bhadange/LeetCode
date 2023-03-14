class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(nums[0] < nums[n-1]) 
            return nums[0];
        int l = 0;
        int r = n-1;
        
        while(l <= r) {
            int mid = (l+r)/2;
            
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid-1] > nums[mid])
                return nums[mid];
            
            if(nums[mid] > nums[0])
                l = mid + 1;
            else 
                r = mid - 1;
        }
        
        return INT_MAX;
    }
};