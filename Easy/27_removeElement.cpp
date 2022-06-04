class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int p = n - 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == val)
                cnt++;

        for (int i = 0; i < n - cnt; i++)
            if (nums[i] == val)
            {
                while (nums[p] == val)
                    p--;
                swap(nums[i], nums[p]);
            }

        return n - cnt;
    }
};