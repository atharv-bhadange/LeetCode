class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for(int i=0; i<colors.size(); i++)
        {
            int j = i+1;
            while(j<n && colors[i]==colors[j])
            {
                if(neededTime[i]>neededTime[j]){
                    ans += neededTime[j];
                    j++;
                }
                else
                {
                    ans += neededTime[i];
                    i = j;
                    j++;
                }
            }
            i = j-1;
        }
        
        return ans;
    }
};