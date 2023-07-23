class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        if(s.size() < t.size())
            return "";
        
        unordered_map<char,int> mp;

        for(auto& x: t)
            mp[x]++;

        int cnt = mp.size();
        int ans = INT_MAX;
        int start = 0;
        int i = 0, j = 0;
        while(j<n) {
            // j calc 
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) {
                    cnt--;
                }
            }
            // if(cnt > 0) {
            //     j++;
            // }
            if(cnt == 0) {
                while(cnt == 0) {
                    if(mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) {
                            cnt++;
                            // ans = min(ans, j-i+1); 
                            if(ans > j-i+1) {
                                ans = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;

        }

        cout<< ans << endl;
        if(ans == INT_MAX) 
            return "";

        return s.substr(start, ans);
    }
};