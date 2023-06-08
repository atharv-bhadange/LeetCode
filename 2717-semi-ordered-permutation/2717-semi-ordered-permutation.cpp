class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int l,r;
        int n =nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==1)
                l=i;
            else if(nums[i]==n)
                r=i;
        }
        
        int ans = l+n-r-1;
        if(l>r)
            ans--;
        return ans;
    }
};