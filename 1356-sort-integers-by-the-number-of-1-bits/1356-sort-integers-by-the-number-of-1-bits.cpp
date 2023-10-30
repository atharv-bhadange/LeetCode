class Solution {
public:
    int count(int n)
    {
        int cnt = 0;
        while(n)
        {
            cnt++;
            n = n & (n-1);
        }
        
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        for(int i=0; i<arr.size(); i++)
        {
            temp.push_back({count(arr[i]),arr[i]});
        }
        sort(temp.begin(),temp.end());
        for(int i=0; i<arr.size(); i++)
        {
            ans.push_back(temp[i].second);
        }
        
        return ans;
    }
};