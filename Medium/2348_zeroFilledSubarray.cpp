class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long int count = 0;
        long long int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count++;
            }
            else
            {
                ans += (count * (count + 1)) / 2;
                count = 0;
            }
        }

        ans += (count * (count + 1)) / 2;

        return ans;
    }
};