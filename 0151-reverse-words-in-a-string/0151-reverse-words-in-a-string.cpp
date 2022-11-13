class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string temp="";
        for(auto& x : s) {
            if(x==' ')
            {
                if(temp!="")
                stk.push(temp);
                temp="";
            }
            else
            {
                temp+=x;
            }
        }
        
        if(temp!="")
            stk.push(temp);
        string ans = "";
        while(!stk.empty()) {
            ans+=stk.top();
            stk.pop();
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;
    }
};