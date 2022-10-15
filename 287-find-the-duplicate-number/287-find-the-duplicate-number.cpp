class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int tort = nums[0];
        int hare = nums[0];
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while (tort != hare);
        
        tort = nums[0];
        while (tort != hare) {
            tort = nums[tort];
            hare = nums[hare];
        }
        
        return hare;
    }
};