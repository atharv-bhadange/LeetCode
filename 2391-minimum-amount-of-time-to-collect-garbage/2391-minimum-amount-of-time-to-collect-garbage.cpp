class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<vector<int>> cnt;
        int n = garbage.size();
        long int ans = 0;
        for(int i=0; i<n; i++)
            ans+=garbage[i].size();
        int lm = -1, lp = -1, lg = -1;
        
        for(int i=n-1; i>=0; i--)
        {
            bool f=0;
            
            for(int j=0; j<garbage[i].size(); j++)
            {
                if(garbage[i][j]=='G')
                {
                    f=1;
                    lg = i;
                    break;
                }
                
            }
            if(f)
                break;
        }
        for(int i=n-1; i>=0; i--)
        {
            bool f=0;
            for(int j=0; j<garbage[i].size(); j++)
            {
                if(garbage[i][j]=='M')
                {
                    f=1;
                    lm = i;
                    break;
                }
                
            }
            if(f)
                break;
        }
        for(int i=n-1; i>=0; i--)
        {
            bool f=0;
            for(int j=0; j<garbage[i].size(); j++)
            {
                if(garbage[i][j]=='P')
                {
                    f=1;
                    lp = i;
                    break;
                }
                
            }
            if(f)
                break;
        }
        
        vector<int> pre(travel.size()+1,0);
        pre[0] = travel[0];
        
        for(int i=1; i<travel.size(); i++)
        {
            pre[i] = pre[i-1] + travel[i];
        }
        
        if(lp!=-1 && lp!=0)
            ans+=pre[lp-1];

        if(lm!=-1 && lm!=0)
            ans+=pre[lm-1];

        if(lg!=-1 && lg!=0)
            ans+=pre[lg-1];


        return ans;
    }
};