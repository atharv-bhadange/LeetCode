class Solution {
public:
    
    int solve(vector<int>& v, int k)
    {
        int ans = 0;
        int curr_sum = 0;
        unordered_map<int,int> m;
        for(int i=0; i<v.size(); i++)
        {
            curr_sum+=v[i];
            if(curr_sum==k)
                ans++;
            if(m.find(curr_sum-k)!=m.end())
                ans+=m[curr_sum-k];
            m[curr_sum]++;
        }
        
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        for(int i=0; i<matrix.size(); i++)
        {
            vector<int> temp(matrix[0].size(), 0);
            for(int j=i; j<matrix.size(); j++)
            {
                for(int k=0; k<matrix[0].size(); k++)
                    temp[k] += matrix[j][k];
                
                ans+=solve(temp, target);
            }
        }
        
        return ans;
    }
};