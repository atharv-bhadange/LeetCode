class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ele = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(cnt==0) {
                ele = nums[i];
                cnt = 1;
            }
            else if(nums[i] == ele)
                cnt++;
            else 
                cnt--;
        }
        cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == ele)
                cnt++;
        }
        
        int c1 = 0;
        int ans = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == ele)
                c1++;
            
            int c2 = cnt - c1;
            if((c1*2 > i+1) && (c2*2 > nums.size() - i - 1)) {
                ans = i;
                break;
            }
        }
    
        return ans;
    }
};