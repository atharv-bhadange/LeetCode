class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(auto& x: nums) {
            if(x>nums[res])
                res++;
        }
        
        return res;
    }
};