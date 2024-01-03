class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto& s: bank) {
            int cnt = 0;
            for(auto& i: s) {
                if(i=='1')
                    cnt++;
            }
            
            if(prev && cnt) {
                ans += prev*cnt;
            }
            if(cnt)
                prev = cnt;
        }
        
        return ans;
    }
};