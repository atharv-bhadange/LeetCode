class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(cnt==0) {
                cnt++;
                ele = nums[i];
            } 
            else if(ele == nums[i]) {
                cnt++;
            }
            else 
                cnt--;
        }
        
        return ele;
    }
};