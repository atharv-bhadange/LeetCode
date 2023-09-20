class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum=0;
        for(auto &i:nums)
            sum+=i;
        int k = sum - x;
        int maxSum = -1, curSum = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            curSum += nums[r];
            while (l <= r && curSum > k)
                curSum -= nums[l++];
            if (curSum == k)
                maxSum = max(maxSum, r - l + 1);
        }

        return maxSum == -1 ? -1 : n - maxSum;
    }
};