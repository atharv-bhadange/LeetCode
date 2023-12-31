class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int ans = -1;
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            } else {
                ans = max(ans, i-mp[s[i]]-1);
            }
        }
        
        return ans;
    }
};