class Solution {
public:
    
    void solve(vector<vector<int>>& rooms, int ver, vector<bool>& vis) {
        vis[ver] = 1;
        
        for(auto& child: rooms[ver]) {
            if(!vis[child]) 
                solve(rooms, child, vis);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        
        solve(rooms, 0, vis);
        
        for(auto x: vis)
            if(!x)
                return x;
        
        return 1;
        
    }
};