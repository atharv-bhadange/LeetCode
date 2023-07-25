typedef pair<int,int> pi;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        priority_queue<pi> pq;
        int n = a.size();
        for(int i=0; i<n; i++) {
            pi p(abs(a[i]-x), a[i]);

            pq.push(p);

            if(pq.size()>k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};