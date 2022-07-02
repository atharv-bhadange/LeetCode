class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int med = nums[nums.size() / 2];
        int a = sum / nums.size();
        long long ans = 0, ans1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += abs(nums[i] - a);
            ans1 += abs(nums[i] - med);
        }

        return min(ans, ans1);
    }
};

// minimum deviation either from mean or from median