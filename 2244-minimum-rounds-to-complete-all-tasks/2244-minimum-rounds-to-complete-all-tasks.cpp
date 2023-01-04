class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto& x: tasks) 
            ++m[x];
        int ans = 0;
        for(auto& x: m) {
            int cur = x.second;
            if(cur==1)
                return -1;
            ans += (cur+2)/3;
        }
        
        return ans;
        
    }
};