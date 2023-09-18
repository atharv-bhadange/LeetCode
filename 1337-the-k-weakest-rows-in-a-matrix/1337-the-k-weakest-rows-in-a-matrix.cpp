class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j=0; j<m; j++)
            {
                cnt+=mat[i][j];
            }
            pq.push(make_pair(cnt,i));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};