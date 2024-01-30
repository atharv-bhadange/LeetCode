class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto &token: tokens) {
            int n = token.size();
            if(isdigit(token[n-1])) {
                int dig = stoi(token);
                st.push(dig);
            } else {
                int a,b;
                if(!st.empty()) {
                    a = st.top();
                    st.pop();
                }
                if(!st.empty()) {
                    b = st.top();
                    st.pop();
                }
                int ans;
                if (token == "+") {
                    ans = a + b;
                } else if (token == "-") {
                    ans = b - a;
                } else if (token == "*") {
                    ans = a * b;
                } else if (token == "/") {
                    ans = b / a;
                }
                st.push(ans);
            }
        }
        
        return st.top();
    }
};