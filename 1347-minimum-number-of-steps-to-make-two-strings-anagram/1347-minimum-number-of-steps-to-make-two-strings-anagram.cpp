class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> ms, mt;
        for(auto& x: s)
            ms[x]++;
        
        for(auto& y: t)
            mt[y]++;
        
        int ans = 0;
        unordered_set<char> st(s.begin(), s.end());
        for(auto& x: st) {
            if(mt[x] < ms[x]) {
                ans += ms[x]-mt[x];
            }
        }
        
        return ans;
    }
};