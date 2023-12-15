class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, pair<int,int>> mp;
        
        for(auto &v: paths) {
            mp[v[0]].first++;
            mp[v[1]].second++;
        }
        
        for(auto& m: mp) {
            if(m.second.first == 0 && m.second.second > 0) {
                return m.first;
            }
        }
       return "";
    }
};