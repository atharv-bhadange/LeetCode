class Solution {
public:
    int MOD = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long> m;
        m[arr[0]] = 1;
        
        for(int i=1;i < arr.size(); i++)
        {
            long count = 1;
            for(auto &x : m)
            {
                int div = x.first;
                if(arr[i]%div == 0 && m.find(arr[i]/div) != m.end())
                {
                    count += m[div]*m[arr[i]/div];
                }
            }
            m[arr[i]] = count;
        }
        int ans = 0;
        for(auto &x : m)
            ans = (ans + x.second) % MOD;
        
        return ans;
    }
};