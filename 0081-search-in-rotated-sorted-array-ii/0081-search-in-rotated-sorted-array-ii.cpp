class Solution {
public:
    
    bool binary(vector<int>& nums, int l, int r, int target) {
        // if(l>=r)
        //     return -1;
        
        while(l<=r) {
            
            while(l<r && nums[l] == nums[l+1])
                l++;
            while(l<r && nums[r] == nums[r-1])
                r--;
            
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return true;
            
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && nums[mid] > target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            else {
                if(nums[mid] < target && nums[r] >= target) 
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        
        return 0;
    }
    
    bool search(vector<int>& nums, int target) {
        return binary(nums, 0, nums.size()-1, target);
    }
};