class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int currFar = 0;
        int currEnd = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            currFar = max(currFar,i+nums[i]);
            if(i==currEnd)
            {
                currEnd = currFar;
                ans++;
            }
        }
        
        return ans;
    }
};