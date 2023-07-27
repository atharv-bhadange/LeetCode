class Solution {
public:
    set<string> ans;
    char checkChar(char c) {
        if(c >= 'a' && c<='z') {
            return char(int(c) - 32);
        }
        else if(c >= 'A' && c<= 'Z') {
            return char(int(c) + 32);
        }
        
        return '&';
    }
    void solve(string ip, string op) {
        if(ip.size() == 0) {
            ans.insert(op);
            return;
        }
        
        string op1 = op;
        char c = checkChar(ip[0]);
        if(c == '&')
            op1.push_back(ip[0]);
        else
            op1.push_back(c);
        op.push_back(ip[0]);
        ip.erase(ip.begin());
        
        solve(ip, op);
        solve(ip, op1);
        
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,"");
        vector<string> a1(ans.begin(),ans.end());
        return a1;
    }
};