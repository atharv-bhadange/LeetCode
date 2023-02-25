class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = INT_MAX;
        int ans = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if(curr_min>prices[i])
                curr_min=prices[i];
            ans = max(prices[i]-curr_min, ans);
        }
        
        return ans;
    }
};