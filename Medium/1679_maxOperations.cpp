class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ct=0;
        m[nums[0]]=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(m[k-nums[i]])
            {
                ct++;
                m[k-nums[i]]--;
                // m[nums[i]]--;
            }
            else
                m[nums[i]]++;
        }
        
        return ct;
    }
};