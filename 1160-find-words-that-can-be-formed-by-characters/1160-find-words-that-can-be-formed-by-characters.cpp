class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        
        for(auto& x: chars) {
            mp[x]++;
        }
        
        int ans = 0;
        
        for(auto& word : words) {
            unordered_map<char,int> t;
            for(auto& x: word) {
                t[x]++;
            }
            bool f = 1;
            for(auto& x: word) {
                if(t[x] > mp[x]) {
                    f = 0;
                    break;
                }
            }
            
            if(f) {
                ans += word.size();
            }
        }
        
        return ans;
    }
};