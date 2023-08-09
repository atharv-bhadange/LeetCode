class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++) {
            int num = i;
            int cnt = 0;
            while(num) {
                num = num & (num-1);
                cnt++;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};