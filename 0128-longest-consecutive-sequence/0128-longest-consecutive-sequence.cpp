class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        int ans = 0;
        int cnt = 1;
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
                if(mp.find(x-1) != mp.end()) {
                    continue;
                }
                else {
                    while(mp.find(x+1) != mp.end()) {
                        cnt++;
                        ans = max(ans, cnt);
                        x++;
                    }
                    cnt = 1;
                }

        }
        
        return ans==0 ? 1 : ans;
    }
};