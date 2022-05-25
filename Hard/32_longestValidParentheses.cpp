class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        int n = s.size();
        int m = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push({'(', i});
            else
            {
                if(!st.empty() && st.top().first=='(')
                {
                    m = max(i-st.top().second+1,m);
                    st.pop();
                    if(!st.empty())
                        m = max(i-st.top().second,m);
                    else 
                        m = max(m,i+1);
                }
                else
                {
                    st.push({')', i});
                }
            }
        }
        
        return m;
    }
};

