class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto& x: tasks) 
            m[x]++;
        int ans = 0;
        for(auto& x: m) {
            int cur = x.second;
            if(cur==1)
                return -1;
            if(cur%3==0)
                ans+= cur/3;
            else
                ans+= cur/3+1;
        }
        
        return ans;
        
    }
};