class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return 0;
        unordered_map<char,int> mp;
        for(auto& x : word1)
            mp[x]++;
        unordered_map<int,int> mint;
        for(auto& x : mp)
            mint[x.second]++;
        unordered_map<char,int> mp2;
        for(auto& x : word2) {
            mp2[x]++;
            if(mp[x]==0)
                return 0;
        }
        // unordered_map<int,int> mint2;
        for(auto& x : mp2){
            mint[x.second]--;
        }
        for(auto& x : mint)
            if(x.second != 0)
                return 0;
        
        return 1;
    }
};