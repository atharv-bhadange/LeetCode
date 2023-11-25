class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int cnt = 0;
        for(auto& w: words) {
            for(auto& c: w) {
                if(c == x)
                {
                    ans.push_back(cnt);
                    break;
                }
            }
            cnt++;
        }
        
        return ans;
    }
};