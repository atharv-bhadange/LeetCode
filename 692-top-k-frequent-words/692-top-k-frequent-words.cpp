class Solution {
public:
    // static bool cmp(pair<int,string>& a, pair<int,string>& b) {
    //     if(a.first==b.first)
    //         return a.second<b.second;
    //     return a.first>b.first;
    // }
    
    struct Comp {
        Comp() {}
        ~Comp() {}
        bool operator() (const pair<string,int>& a, const pair<string,int>& b) {
            if(a.second==b.second)
                return a.first<b.first;
            return a.second>b.second;
        }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto& x: words) 
            mp[x]++;
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, Comp> pq;
        for(auto& x: mp) {
            pq.emplace(x);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};