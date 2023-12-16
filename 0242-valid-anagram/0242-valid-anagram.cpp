class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(int i = 0; i<s.size(); i++)
            m[s[i]]++;
    
        for(int i=0; i<t.size(); i++)
            m[t[i]]--;
        
        for(auto p : m)
            if(p.second!=0)
                return false;
        
        return true;
    }
};