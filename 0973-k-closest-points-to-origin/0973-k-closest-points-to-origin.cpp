typedef pair<int,int> pi;
typedef pair<double, pi> ppi;

class Solution {
public:
    double euclidean(int x, int y) {
        return sqrt(x*x + y*y);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        priority_queue<ppi> pq;

        vector<vector<int> > ans;

        for(auto& x: a) {
            ppi p(euclidean(x[0],x[1]), {x[0], x[1]});
            pq.push(p);

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()) {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};