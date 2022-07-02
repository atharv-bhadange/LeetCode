class Solution
{
public:
    int MOD = 1e9 + 7;

    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxH = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        // maxH = max(maxH, h-horizontalCuts[horizontalCuts.size()-1]);

        int maxW = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        }
        // maxW = max(maxH, w-verticalCuts[verticalCuts.size()-1]);

        long long int ans = (1LL * maxH * maxW) % MOD; 

        return ans;
    }
};

// 1LL took the day