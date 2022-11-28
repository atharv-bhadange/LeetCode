class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto& m : matches) {
            int win = m[0];
            int loss = m[1];
            if(mp.find(win)==mp.end())
                mp[win] = 0;
            mp[loss]++;
        }
        vector<int> winners;
        vector<int> loosers;
        for(auto& m : mp) {
            if(m.second==1) 
                loosers.push_back(m.first);
            else if(m.second==0)
                winners.push_back(m.first);
        }
        
        return {winners,loosers};
    }
};