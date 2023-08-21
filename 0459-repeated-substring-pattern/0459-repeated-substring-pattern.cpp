class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1; i<=n/2; i++) {
            if(n%i == 0) {
                string p = s.substr(0,i);
                string ptr = "";
                for(int j=0; j<n/i; j++) {
                    ptr += p;
                }
                if(ptr == s)
                    return true;
            }
        }
        
        return false;
    }
};