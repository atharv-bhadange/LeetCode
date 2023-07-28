class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> mp;
        
        for(int i=0; i<pieces.size(); i++) {
            mp[pieces[i][0]] = i;
        }
        
        int i=0;
        int ans = 0;
        for(;i<arr.size(); i++) {
            if(mp.find(arr[i]) != mp.end()) {
                int k = 0;
                int j = mp[arr[i]];
                // bool f = 1;
                int t = i;
                while(t<arr.size() && k<pieces[j].size() && arr[t] == pieces[j][k]) {
                    t++;
                    k++;
                }
                if(k == pieces[j].size()) {
                    ans++;
                }
            }
        }
        return ans==pieces.size();
    }
};