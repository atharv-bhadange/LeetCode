class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> mp;
        mp['a']=1;
        mp['A']=1;
        mp['e']=1;
        mp['E']=1;
        mp['i']=1;
        mp['I']=1;
        mp['o']=1;
        mp['O']=1;
        mp['u']=1;
        mp['U']=1;
        
        string v = "";
        // vector<int> idx;
        for(int i=0 ; i<s.size(); i++) {
            if(mp[s[i]]==1) {
                v += s[i];
                // idx.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        
        string t = "";
        int j = 0;
        for(int i=0; i<s.size(); i++) {
            if(mp[s[i]]==1) {
                t += v[j++];
            }
            else 
                t += s[i];
        }
        
        return t;
    }
};