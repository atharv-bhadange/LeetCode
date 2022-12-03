class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto& x : s)
            m[x]++;
        vector<pair<int,char> > vp;
        for(auto& x: m)
            vp.push_back({x.second,x.first});
        
        sort(vp.rbegin(),vp.rend());
        string ans;
        for(auto& x: vp) {
            // cout<<x.first<< " " << x.second <<endl;
            while(x.first--)
                ans.push_back(x.second);
        }
        
        return ans;
    }
};