class Solution {
public:
    string largestGoodInteger(string num) {
        int j = 0;
        int i = 0;
        
        unordered_map<char,int> mp;
        int sz = 0;
        string ans = "";
        int n = num.size();
        while(j<n) {
            if(j-i+1 != 3) {
                mp[num[j]]++;
                sz = mp.size();
                j++;
            }
            else if(j-i+1 == 3) {
                if(mp[num[j]] == 0) {
                    sz++;
                }
                mp[num[j]]++;
                
                if(sz == 1 && mp[num[j]] == 3) {
                    string t = string(3, num[j]);

                    ans = max(t, ans);
                }

                mp[num[i]]--;
                if(mp[num[i]] == 0) {
                    sz--;
                }
                i++;
                
                j++;
            }
        }
        
        return ans;
    }
};