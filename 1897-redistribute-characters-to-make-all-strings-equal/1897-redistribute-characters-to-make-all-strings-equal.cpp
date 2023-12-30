class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        
        for(auto& word: words) {
            for(int i=0; i<word.size(); i++) {
                mp[word[i]]++;
            }
        }
        
        int n = words.size();
        
        for(auto& x: mp) {
            if(x.second % n != 0)
                return false;
        }
        
        return true;
    }
};