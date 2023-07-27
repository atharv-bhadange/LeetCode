class Solution {
public:
    vector<string> ans;
    void solve(string op, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }
        if(open>0) {
            op.push_back('(');
            solve(op,open-1,close);
            op.pop_back();
        }
        
        if(close>0 && close > open) {
            op.push_back(')');
            solve(op,open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, n);
        return ans;
    }
};