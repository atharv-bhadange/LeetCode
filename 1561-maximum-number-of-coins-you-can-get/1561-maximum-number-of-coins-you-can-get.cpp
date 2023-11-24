class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        
        int n = piles.size();
        
        int ans = 0;
        int j = n-1;
        for(int i=0; i<j; i++) {
            if(i%2 == 1)
                ans += piles[i], j--;
        }
        
        return ans;
    }
};