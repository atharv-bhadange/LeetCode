typedef pair<int,int> pi;

class MyComp
{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            if(a.first==b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;

        }
};

class Solution {
public:
    static bool cmp(const pi a,const pi b) {
        if(a.first == b.first) 
            return a.second < b.second;
        return a.first > b.first;
    }
    
    vector<int> frequencySort(vector<int>& a) {
         priority_queue<pi, vector<pi>, MyComp > pq;

        unordered_map<int,int> mp;

        for(auto& x: a) {
            mp[x]++;
        }

        for(auto& x: mp) {
            pi p(x.second, x.first);

            pq.push(p);

            // if(pq.size() > k)
            //     pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            // cout<<pq.top().second<<" ";
            pi p = pq.top();
            while(p.first--) {
                ans.push_back(p.second);
            }

            pq.pop();
        }
        
        return ans;
    }
};