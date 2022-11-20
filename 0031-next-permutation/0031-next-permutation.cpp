class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        
        if(nums[n-1] > nums[n-2]) {
            swap(nums[n-1],nums[n-2]);
            return;
        }
        int i = n-1;
        
        while(i >0 && nums[i] <= nums[i-1]) {
            i--;
        }
        int idx = -1;
        int mini = INT_MAX;
            // cout<<i<<endl;
        
        if(i>0) {
            for(int j=i; j<n; j++) 
            {
                if(nums[j]>nums[i-1] && mini > nums[j]) {
                    mini = nums[j];
                    idx = j;
                    // cout<<mini<<endl;
                } 
                // cout<<nums[j]<<endl;
            }
            // cout<<nums[i]<<' '<<idx<<endl;
            if(idx!=-1)
            {
                swap(nums[idx],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        
        sort(nums.begin(),nums.end());
    }
};