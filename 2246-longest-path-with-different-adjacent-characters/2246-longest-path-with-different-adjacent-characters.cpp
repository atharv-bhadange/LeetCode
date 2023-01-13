class Solution {
public:
    int dfs(int ver, vector<vector<int>>& children, string& s, int& ans) {
        int path1 = 0, path2 = 0;
        for(auto& child : children[ver]) {
            int cur = dfs(child, children, s, ans);
            if(s[ver] == s[child])
                continue;
            if(cur > path2)
                path2 = cur;
            if(path2 > path1)
                swap(path1, path2);
        }
        
        ans = max(ans, path1+path2+1);
        return path1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n, vector<int>());
        
        for(int i=1; i<n; i++) {
            children[parent[i]].push_back(i);
        }
        int ans = 0;
        dfs(0, children, s, ans);
        return ans;
    }
};