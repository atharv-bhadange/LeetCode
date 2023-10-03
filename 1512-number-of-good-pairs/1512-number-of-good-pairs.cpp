class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        int ans = 0;
        for(auto &p : m)
        {
            int x = p.second;
            ans += (x*(x-1))/2;
        }
        
        return ans;
    }
};