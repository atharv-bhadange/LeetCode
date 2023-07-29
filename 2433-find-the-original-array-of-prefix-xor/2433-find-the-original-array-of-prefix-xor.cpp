class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> pre;
        int x = pref[0];
        pre.push_back(x);

        for(int i=1; i<pref.size(); i++) {
            pre.push_back(x^pref[i]);
            x = pref[i];
        }
        
        return pre;
    }
};