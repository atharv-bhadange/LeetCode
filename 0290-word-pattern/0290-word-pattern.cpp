class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vs;
        string temp = "";
        for(auto& x : s) {
            if(x==' ') {
                vs.push_back(temp);
                temp = "";
            }
            else {
                temp += x;
            }
        }
        vs.push_back(temp);
        if(vs.size() != pattern.size())
            return false;
        // unordered_map<char, string> m;
        unordered_map<string, char> m;
        vector<bool> done(26,0);
        for(int i=0; i<pattern.size(); i++) {
            if(m.find(vs[i]) == m.end() ) {
                m[vs[i]] = pattern[i];
                if(done[pattern[i]-'a'])
                    return false;
                done[pattern[i]-'a'] = 1;
            }
            else {
                
                if(m[vs[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};