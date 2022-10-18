class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        while(--n) {
            string temp = "";
            for(int i=0; i<ans.size(); i++) {
                int cnt=1;
                 
                while(i+1<ans.size() && ans[i]==ans[i+1]) {
                    cnt++;
                    i++;
                }
                temp += (to_string(cnt) + ans[i]);
            }
            ans = temp;
        }
        
        return ans;
    }
};