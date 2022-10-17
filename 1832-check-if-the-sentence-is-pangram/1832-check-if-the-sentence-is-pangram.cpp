class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int> mp;
        for(auto& x : sentence)
            mp[x]++;
        if(mp.size()==26)
            return true;
        return false;
    }
};