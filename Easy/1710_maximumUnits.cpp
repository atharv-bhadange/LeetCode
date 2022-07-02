class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] > b[0];
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>> &boxType, int truckSize)
    {
        sort(boxType.begin(), boxType.end(), cmp);
        int boxes = 0;
        int units = 0;
        int ans = 0;
        for (int i = 0; i < boxType.size(); i++)
        {
            if (boxType[i][0] < truckSize)
            {
                boxes = boxType[i][0];
                units = boxType[i][1];
                ans += boxes * units;
                truckSize -= boxType[i][0];
            }
            else
            {
                boxes = truckSize;
                units = boxType[i][1];
                ans += boxes * units;
                truckSize = 0;
            }
        }

        return ans;
    }
};