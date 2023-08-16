class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        while(i<n) {
            // cout<<i<<" "<<j<<endl;
            if(nums[i]==0) {
                j = i+1;
                while(j<n && nums[j]==0) {
                    j++;
                }
                if(j<n)
                    swap(nums[i], nums[j]);
            }
            i++;
        }
    }
};