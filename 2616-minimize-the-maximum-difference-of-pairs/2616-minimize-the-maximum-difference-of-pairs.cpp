class Solution {
public:
    
    bool findAtleastP(int mid, int p, vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i++;
            }
            if(cnt==p)
                return true;
        }
        
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int ans = 0;
        if(!p)
            return ans;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[nums.size()-1]-nums[0];
        int mid;
        while(l<r) {
            mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(findAtleastP(mid, p, nums)) {
                r=mid;
            }
            else 
                l=mid+1;
        }
        
        if(findAtleastP(r, p, nums)){
            return r;
        }        
        return l;
    }
};