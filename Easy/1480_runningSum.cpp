class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> r(n, 0);

        r[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            r[i] = r[i - 1] + nums[i];
        }
        // r.pop_front();

        return r;
    }
};