class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return n;
        int ans = -1;
        map<int,int> m1,m2;
        for(int i=0; i<trust.size(); i++) {
            m1[trust[i][0]]++;
            m2[trust[i][1]]++;
        }
        for(auto &x : m2) {
            if(x.second == n-1) {
                ans = x.first;
                break;
            }
        }
        if(ans==-1)
            return ans;
        if(m1[ans]==0)
            return ans;
        
        return -1;
    }
};