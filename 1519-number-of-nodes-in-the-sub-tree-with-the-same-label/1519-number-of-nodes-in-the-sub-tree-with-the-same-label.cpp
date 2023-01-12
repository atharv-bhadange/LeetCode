class Solution {
public:
    vector<int> dfs(int ver, int parent, string& s, vector<vector<int>>& graph, vector<int>& ans){
        vector<int> verCnt(26);
        verCnt[s[ver] - 'a'] = 1; 
        for(auto& child : graph[ver]) {
            if(child==parent)
                continue;
            vector<int> childCnt = dfs(child, ver, s,graph, ans);
            for(int i=0; i<26; i++) {
                verCnt[i] += childCnt[i];
            }
        }
        
        ans[ver] = verCnt[s[ver] - 'a'];
        return verCnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        dfs(0, -1, labels, graph, ans);
        return ans;
    }
};