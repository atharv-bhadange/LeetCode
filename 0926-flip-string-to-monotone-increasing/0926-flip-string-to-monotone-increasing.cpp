class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int num = 0;
        for(auto& c : s) {
            if(c == '0') {
                ans = min(num, ans + 1);
            } else {
                num++;
            }
        }
        
        return ans;
    }
};