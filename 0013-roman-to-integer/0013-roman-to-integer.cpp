class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int n = s.size();
        int i = n-1;
        
        int ans = 0;
        while(i-1 >= 0) {
            if(mp[s[i-1]] < mp[s[i]])
                ans += (mp[s[i]] - mp[s[i-1]]), i--;
            else
                ans += mp[s[i]];
            i--;
            cout<<ans<<endl;
        }
        // cout<<mp[s[i]]<<" "<<ans;
        if(i>=0)
            ans += mp[s[i]];
        
        return ans;
    }
};