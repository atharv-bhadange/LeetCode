class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size()-1, m = 0;
        while(m<=h) {
            if(nums[m]==0) {
                swap(nums[l], nums[m]);
                l++, m++;
            }
            else if(nums[m]==2) {
                swap(nums[h],nums[m]);
                h--;
            }
            else 
                m++;
        }
    }
};