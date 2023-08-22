class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.size())
            return false;
        int i=0;
        for(auto& x: words) {
            if(x[0] != s[i++])
                return false;
        }
        
        return true;
    }
};