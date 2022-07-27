class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int hare = nums[0];
        int tort = nums[0];
        // finding if cycle
        do
        {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while (tort != hare);
        tort = nums[0];

        // finding cycles entrance
        while (tort != hare)
        {
            tort = nums[tort];
            hare = nums[hare];
        }
        return tort;
    }
};