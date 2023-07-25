typedef pair<int,int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        priority_queue<pi, vector<pi>, greater<pi> > pq;

        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto& x: a) {
            mp[x]++;
        }

        for(auto& x: mp) {
            pi p(x.second, x.first);

            pq.push(p);

            if(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};