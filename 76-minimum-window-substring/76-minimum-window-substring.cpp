class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0, r = 0;
        int cnt = t.size();
        int head = 0, d = INT_MAX;
        vector<int> map(128, 0);
        for(auto& c : t)
            map[c]++;
        
        while(r<n) {
            if(map[s[r++]]-- > 0) cnt--;
            while(cnt==0) {
                if(r-l<d) 
                    d = r-l, head = l;
                if(map[s[l++]]++ == 0) cnt++;
            }
        }
        
        return d==INT_MAX ? "" : s.substr(head, d);
    }
};