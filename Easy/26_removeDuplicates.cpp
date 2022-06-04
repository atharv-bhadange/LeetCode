class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int p = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[p] = nums[i + 1];
                p++;
            }
        }

        return p;
    }
};