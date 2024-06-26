class Solution {
public:
    const int INF = 1e9+7;
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        
        while(l<r) {
            int mid = (l+r)/2;
            
            int curr = 0;
            if(target < nums[0] == nums[mid] < nums[0]) {
                curr = nums[mid];
            }
            else {
                curr = (target < nums[0]) ? -INF : INF;
            }
            
            if(curr<target)
                l = mid+1;
            else if(curr>target)
                r = mid;
            else
                return mid;
        }
        
        return -1;
    }
};