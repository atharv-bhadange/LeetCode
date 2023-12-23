class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x = 0, y = 0;
        unordered_map<char, pair<int,int>> mp;
        mp['N'] = {0, 1};
        mp['E'] = {1, 0};
        mp['S'] = {0, -1};
        mp['W'] = {-1, 0};
        
        st.insert({x,y});
        
        for(int i=0; i<path.size(); i++) {
            x += mp[path[i]].first;
            y += mp[path[i]].second;
            if(st.find({x,y}) == st.end()) {
                st.insert({x,y});
            } else {
                return true;
            }
        }
        
        
        
        return false;
    }
};