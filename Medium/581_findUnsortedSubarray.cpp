class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> k = nums;
        sort(nums.begin(), nums.end());
        int st = 0, end = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (k[i] != nums[i])
            {
                st = i;
                break;
            }
        }
        for (int i = k.size() - 1; i >= 0; i--)
        {
            if (k[i] != nums[i])
            {
                end = i;
                break;
            }
        }

        if (st == 0 && end == 0)
            return 0;
        return end - st + 1;
    }
};