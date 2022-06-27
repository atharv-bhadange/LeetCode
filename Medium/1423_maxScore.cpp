class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> pre(n + 1, 0);
        // pre[0] = cardPoints[0];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + cardPoints[i];
            sum += cardPoints[i];
        }
        int l = 0;
        int r = n - k;
        int m = INT_MAX;
        for (; r < n + 1; r++, l++)
        {
            m = min(m, pre[r] - pre[l]);
            // cout<<m<<" ";
        }

        return (sum - m);
    }
};

// classic sliding window problem 
// idiot me forgot to change my perspective and 
// calculate the subarray of length n-k with minimum sum 