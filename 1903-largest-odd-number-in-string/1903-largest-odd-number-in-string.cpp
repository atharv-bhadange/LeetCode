class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        
        string ans = "";
        int idx = -1;
        for(int i=n-1; i>=0; i--) {
            if((num[i]-'0')%2 != 0) {
                idx = i;
                break;
            }
        }
        

        for(int i=0; i<=idx; i++)
            ans += num[i];

        
        return ans;
    }
};